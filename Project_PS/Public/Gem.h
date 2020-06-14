// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "GameFramework/Pawn.h"

#include "PS_Std.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include <ConstructorHelpers.h>

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

public:
   GemID MakeGemID(double seed)
    {
        double cosSeed = cos(seed);
        uint8 id = static_cast<int>(cosSeed * 10000) % 3;
        return GemID(id);
    };
public:
    inline GemID& GetID() { return mID; };
    inline UINT8& GetIdx() { return mIdx; };
    inline const GemID GetID() const { return mID; };
    inline const UINT8 GetIdx() const { return mIdx; };

    inline void SetID(const GemID& setid) { mID = setid; };
    inline void SetIdx(const UINT8& setidx) { mIdx = setidx; };

    void SetGem(const double& seed,const UINT8& idx,const FVector& pos, AGemColorObj* pColorObj);

private:

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* mMesh;

    FVector mPosition;
    GemID mID;
    UINT8 mIdx;


public:
  
};
