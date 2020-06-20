// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSpot.h"
#include "GameMode_PS.h"

#include "Engine/Classes/Components/InputComponent.h"
// Sets default values
APlayerSpot::APlayerSpot()
{

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    SetRootComponent(mpMesh);
    mpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    ConstructorHelpers::FObjectFinder<UStaticMesh> TMesh(TEXT("StaticMesh'/Game/MyGame_/StaticMesh/Cube.Cube'"));
    if (TMesh.Succeeded())
    {
        mpMesh->SetStaticMesh(TMesh.Object);
    }
    

}

// Called when the game starts or when spawned
void APlayerSpot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
 
}

// Called to bind functionality to input
void APlayerSpot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
   
}

void APlayerSpot::Up(uint8& spotCount)
{
    
    if (spotCount <mpBoardStd->mSizeX)
    {
        spotCount++;
        FVector ActorPos = GetActorLocation();
        ActorPos.X += mpBoardStd->mLengthX;
        SetActorLocation(ActorPos);
    }
}
void APlayerSpot::Down(uint8& spotCount)
{
    if (spotCount > 1)
    {
        spotCount--;
        FVector ActorPos = GetActorLocation();
        ActorPos.X -= mpBoardStd->mLengthX;
        SetActorLocation(ActorPos);
    }
}
void APlayerSpot::Left(uint8& spotCount)
{
    if (spotCount > 1)
    {
        spotCount--;
        FVector ActorPos = GetActorLocation();
        ActorPos.Y -= mpBoardStd->mLengthY;
        SetActorLocation(ActorPos);
    }
}
void APlayerSpot::Right(uint8& spotCount)
{
    if (spotCount < mpBoardStd->mSizeY)
    {
        spotCount++;
        FVector ActorPos = GetActorLocation();
        ActorPos.Y += mpBoardStd->mLengthY;
        SetActorLocation(ActorPos);
    }
}
void APlayerSpot::Esc()
{

};