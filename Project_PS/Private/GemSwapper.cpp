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
void GemSwapper::Set_Gem(AGem* gem)
{
    if (mCounter>1)
    {
        KLOG(Warning, TEXT("%s"), TEXT("GemSwapper->m_Counter>1"));
        return;
    }
    mSwapper[mCounter] = gem;
    mCounter = mCounter ^ 1;
}
