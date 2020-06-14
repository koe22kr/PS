// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <ConstructorHelpers.h>

#include "GemColorObj.generated.h"

UCLASS()
class PROJECT_PS_API AGemColorObj : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGemColorObj();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    UStaticMesh* mRed;
    UStaticMesh* mBlue;
    UStaticMesh* mGreen;
};
