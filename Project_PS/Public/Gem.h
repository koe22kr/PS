// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "GameFramework/Pawn.h"

#include "Engine/Classes/Components/StaticMeshComponent.h"
#include <ConstructorHelpers.h>

#include "PS_Std.h"
#include "GemColorObj.h"

#include "Gem.generated.h"

class AGemColorObj;

UCLASS()
class PROJECT_PS_API AGem : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
    AGem();
   
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

    UStaticMesh* GetColorMesh(GemColor& gemcolor)
    {
        if (gemcolor == GemColor::RED)
        {
            return mpColorObj->mRed;
        }
        else if (gemcolor == GemColor::BLUE)
        {
            return mpColorObj->mBlue;
        }
        else
        {
            return mpColorObj->mGreen;
        }
    }
     
    
    GemColor MakeGemID(double seed)
    {
        double cosSeed = cos(seed);
        uint8 id = static_cast<int>(cosSeed * 10000) % 3;
        return GemColor(id);
    };
public:
    inline GemColor& GetColor() { return mColor; };
    inline UINT8& GetIdx() { return mIdx; };
    inline const GemColor& GetColor() const { return mColor; };
    inline const UINT8& GetIdx() const { return mIdx; };

    inline void SetColor(const GemColor& setcolor) {
        mColor = setcolor; 
        mMesh->SetStaticMesh(GetColorMesh(mColor));
    };

    inline void SetIdx(const UINT8& setidx) { mIdx = setidx; };
    
    
    
    void InitGem(const double& seed,const UINT8& idx,const FVector& pos, AGemColorObj* pColorObj);

private:
    AGemColorObj* mpColorObj;
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* mMesh;

    FVector mPosition;
    GemColor mColor;
    UINT8 mIdx;


public:
  
};
