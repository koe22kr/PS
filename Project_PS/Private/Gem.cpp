// Fill out your copyright notice in the Description page of Project Settings.


#include "Gem.h"
#include "GemColorObj.h"
// Sets default values
AGem::AGem()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    //RootComponent = mpMesh;
    mpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    SetRootComponent(mpMesh);



   
};

void AGem::InitGem(const double& seed,const uint32& idx, const FVector& pos, AGemColorObj* ColorObj)
{
    mpColorObj = ColorObj;
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

void AGem::SetPos(const FVector& pos) 
{ 
    mPosition = pos;
    SetActorLocation(pos);
    
};

void AGem::SetGem(AGem* gem, uint32 idx)
{
    //SetColor(gem->GetColor());
    SetPos(gem->mPosition);
    if (idx)
    {
        SetIdx(idx);
    }
    else
    {
        SetIdx(gem->GetIdx());

    }
}
void AGem::SetGem(const FVector& gempos, const uint32& idx)
{
    SetPos(gempos);
    SetIdx(idx);
}