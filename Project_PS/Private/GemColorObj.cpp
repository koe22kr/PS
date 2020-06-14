// Fill out your copyright notice in the Description page of Project Settings.


#include "GemColorObj.h"

// Sets default values
AGemColorObj::AGemColorObj()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    ConstructorHelpers::FObjectFinder<UStaticMesh> TMESH(TEXT("StaticMesh'/Game/MyGame_/StaticMesh/Red.Red'"));
    mRed = TMESH.Object;
    ConstructorHelpers::FObjectFinder<UStaticMesh> TMESH2(TEXT("StaticMesh'/Game/MyGame_/StaticMesh/Blue.Blue'"));
    mBlue = TMESH2.Object;
    ConstructorHelpers::FObjectFinder<UStaticMesh> TMESH3(TEXT("StaticMesh'/Game/MyGame_/StaticMesh/Green.Green'"));
    mGreen = TMESH3.Object;
}

// Called when the game starts or when spawned
void AGemColorObj::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGemColorObj::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

