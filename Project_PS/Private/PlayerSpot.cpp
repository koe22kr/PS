// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSpot.h"
#include "GameMode_PS.h"
#include "GemSwapper.h"
#include "Engine/Classes/Components/InputComponent.h"
// Sets default values
APlayerSpot::APlayerSpot()
{

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    mpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    ConstructorHelpers::FObjectFinder<UStaticMesh> TMesh(TEXT("StaticMesh'/Game/MyGame_/StaticMesh/Cube.Cube'"));
    if (TMesh.Succeeded())
    {
        mpMesh->SetStaticMesh(TMesh.Object);
    }
    SetRootComponent(mpMesh);


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

void APlayerSpot::Up(int& spotCountX, int& spotCountY)
{
    
    if (spotCountX <mpBoardStd->mSizeX)
    {
        spotCountX++;
        FVector ActorPos = GetActorLocation();
        ActorPos.X += mpBoardStd->mLengthX;
        SetActorLocation(ActorPos);

        PutandSwap(spotCountX, spotCountY);
    }
}
void APlayerSpot::Down(int& spotCountX, int& spotCountY)
{
    if (spotCountX > 1)
    {
        spotCountX--;
        FVector ActorPos = GetActorLocation();
        ActorPos.X -= mpBoardStd->mLengthX;
        SetActorLocation(ActorPos);

        PutandSwap(spotCountX, spotCountY);
    }
}
void APlayerSpot::Left(int& spotCountX, int& spotCountY)
{
    if (spotCountY > 1)
    {
        spotCountY--;
        FVector ActorPos = GetActorLocation();
        ActorPos.Y -= mpBoardStd->mLengthY;
        SetActorLocation(ActorPos);

        PutandSwap(spotCountX, spotCountY);
    }
}
void APlayerSpot::Right(int& spotCountX, int& spotCountY)
{
    if (spotCountY < mpBoardStd->mSizeY)
    {
        spotCountY++;
        FVector ActorPos = GetActorLocation();
        ActorPos.Y += mpBoardStd->mLengthY;
        SetActorLocation(ActorPos);

        PutandSwap(spotCountX, spotCountY);
    }
}
void APlayerSpot::Esc()
{

};

void APlayerSpot::Init()
{
    AGem* gem = mpBoard->GetGem(0,0);
    mpSwapper->Put(gem);
}

void APlayerSpot::PutandSwap(int& spotCountX, int& spotCountY)
{
    AGem* gem = mpBoard->GetGem(spotCountX - 1, spotCountY - 1);
    mpSwapper->Put(gem);
    FVector2D indexpair = mpSwapper->Swap();
    mpBoard->SwapGem(indexpair.X,indexpair.Y);
}
