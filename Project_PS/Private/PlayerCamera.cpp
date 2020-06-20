// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCamera.h"
#include "Engine/World.h"
#include "PlayerSpot.h"
// Sets default values
APlayerCamera::APlayerCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    mSpotCountX, mSpotCountY, mCameraCountX, mCameraCountY = 1;
    mCameraMoveOffset = 3;
    AutoPossessPlayer = EAutoReceiveInput::Player0;
    
    bUseControllerRotationYaw = true;
    mpSpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
    mpSpringArm->TargetArmLength = 1000;
    mpSpringArm->bUsePawnControlRotation = true;
    mpCamera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");
    if (!SetRootComponent(mpSpringArm))
    {
        KLOG_S(Warning);
    }
    mpCamera->SetupAttachment(mpSpringArm);
    mpCamera->SetRelativeLocation(FVector(0, 0, 200));

}

// Called when the game starts or when spawned
void APlayerCamera::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAction(TEXT("Up"), IE_Pressed, this, &APlayerCamera::Up);
    PlayerInputComponent->BindAction(TEXT("Down"), IE_Pressed, this, &APlayerCamera::Down);
    PlayerInputComponent->BindAction(TEXT("Left"), IE_Pressed, this, &APlayerCamera::Left);
    PlayerInputComponent->BindAction(TEXT("Right"), IE_Pressed, this, &APlayerCamera::Right);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerCamera::Turn);
    PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerCamera::LookUp);

}

void APlayerCamera::Up()
{
    mpPlayerSpot->Up(mSpotCountX);
    if ((mSpotCountX - mCameraCountX) >= mCameraMoveOffset)
    {
        mCameraCountX++;
        FVector ActorPos = GetActorLocation();
        ActorPos.X += mpBoardStd->mLengthX;
        SetActorLocation(ActorPos);
    }
}
void APlayerCamera::Down()
{
    mpPlayerSpot->Down(mSpotCountX);
    if ((mCameraCountX - mSpotCountX) >= mCameraMoveOffset)
    {
        mCameraCountX--;
        FVector ActorPos = GetActorLocation();
        ActorPos.X -= mpBoardStd->mLengthX;
        SetActorLocation(ActorPos);
    }
}
void APlayerCamera::Left()
{
    mpPlayerSpot->Left(mSpotCountY);
    if ( (mCameraCountY - mSpotCountY) >= mCameraMoveOffset)
    {
        mCameraCountY--;
        FVector ActorPos = GetActorLocation();
        ActorPos.Y -= mpBoardStd->mLengthY;
        SetActorLocation(ActorPos);
    }
}
void APlayerCamera::Right()
{
    mpPlayerSpot->Right(mSpotCountY);
    if ((mSpotCountY- mCameraCountY) >= mCameraMoveOffset)
    {
        mCameraCountY++;
        FVector ActorPos = GetActorLocation();
        ActorPos.Y += mpBoardStd->mLengthY;
        SetActorLocation(ActorPos);
    }
}

void APlayerCamera::Turn(float axis)
{
    AddControllerYawInput(axis);
}
void APlayerCamera::LookUp(float axis)
{
    AddControllerPitchInput(axis);
}
