// Fill out your copyright notice in the Description page of Project Settings.


#include "GemSwapper.h"
#include "Project_PS.h"
GemSwapper::GemSwapper()
{
    mCounter = 0;
}

GemSwapper::~GemSwapper()
{
}
void GemSwapper::Put(AGem* gem)
{
    if (mCounter>1)
    {
        KLOG(Warning, TEXT("%s"), TEXT("GemSwapper->m_Counter>1"));
        return;
    }
    mSwapper[mCounter] = gem;
    //mCounter = mCounter ^ 1;
    if (mCounter==0)
    {
        mCounter = 1;
    }
}


FVector2D GemSwapper::Swap()
{
   //GemColor tempcolor = mSwapper[0]->GetColor();
   FVector temppos = mSwapper[0]->GetPos();
   FVector temppos2 = mSwapper[0]->GetPos();
   uint32 tempidx = mSwapper[0]->GetIdx();
   uint32 tempidx2 = mSwapper[1]->GetIdx();
    mSwapper[0]->SetGem(temppos2, tempidx2);
    mSwapper[1]->SetGem(temppos, tempidx);
    return FVector2D(tempidx, tempidx2);
}
