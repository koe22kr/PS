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
        uint32 id = static_cast<int>(cosSeed * 10000) ;
        return GemColor(id % 3);
    };
public:
    inline GemColor& GetColor() { return mColor; };
    inline uint32& GetIdx() { return mIdx; };
    inline const GemColor& GetColor() const { return mColor; };
    inline const uint32& GetIdx() const { return mIdx; };
    inline const FVector& GetPos() const { return mPosition; };
    void InitGem(const double& seed, const uint32& idx, const FVector& pos, AGemColorObj* colorobj);

    //
public:
    void SetGem(AGem* gem, uint32 idx = 0);
    void SetGem(const FVector& gempos,const uint32& idx);

private:
    inline void SetColor(const GemColor& setcolor) {
        mColor = setcolor; 
        mpMesh->SetStaticMesh(GetColorMesh(mColor));
    };
    void SetPos(const FVector& pos);
    inline void SetIdx(const uint32& setidx) { mIdx = setidx; };

    
    //

private:
    AGemColorObj* mpColorObj;
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* mpMesh;

    FVector mPosition;
    GemColor mColor;
    uint32 mIdx;


public:
  
};
