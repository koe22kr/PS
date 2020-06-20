// Fill out your copyright notice in the Description page of Project Settings.


#include "Gem.h"
#include "GemColorObj.h"
// Sets default values
AGem::AGem()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    //RootComponent = mpMesh;
    SetRootComponent(mpMesh);
    mpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));



   
};

void AGem::InitGem(const double& seed,const UINT8& idx, const FVector& pos, AGemColorObj* pColorObj)
{
    mpColorObj = pColorObj;
    mIdx = idx;
    mPosition = pos;
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
   
    //    mMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh222"));

    mColor = MakeGemID(seed + 0.1);
    if (!mpMesh->SetStaticMesh(GetColorMesh(mColor)))
    {
        KLOG_S(Warning);
    }
  
};


// Called when the game starts or when spawned5
void AGem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

