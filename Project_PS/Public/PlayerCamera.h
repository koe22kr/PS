// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PS_Std.h"


#include "Engine/Classes/Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Pawn.h"

#include "PlayerCamera.generated.h"

class APlayerSpot;
//class GameBoard;

UCLASS()
class PROJECT_PS_API APlayerCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
    int mSpotCountX;
    int mSpotCountY;
    int mCameraCountX;
    int mCameraCountY;

    int mCameraMoveOffset;
public:
    APlayerSpot* mpPlayerSpot;
    Board_Std* mpBoardStd;
    //GameBoard* mpBoard;
    UPROPERTY(VisibleAnywhere,Category = "Camera")
    UCameraComponent* mpCamera;
    UPROPERTY(VisibleAnywhere, Category = "Camera")
    USpringArmComponent* mpSpringArm;
public:
    void Init() {};
    void Up();
    void Down();
    void Left();
    void Right();

    void Turn(float axis);
    void LookUp(float axis);
};
