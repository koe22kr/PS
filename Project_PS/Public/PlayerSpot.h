// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PS_Std.h"

#include "GameFramework/Character.h"
#include "PlayerSpot.generated.h"

UCLASS()
class PROJECT_PS_API APlayerSpot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerSpot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* mpMesh;
    Board_Std* mpBoardStd;
private://|x,y count| > n  => camera move;


public:
    void Up(uint8& spotCount);
    void Down(uint8& spotCount);
    void Left(uint8& spotCount);
    void Right(uint8& spotCount);
    void Esc();// {};
};
