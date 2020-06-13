// Fill out your copyright notice in the Description page of Project Settings.


#include "GemSwapper.h"
#include "Project_PS.h"
Gem_Checker::Gem_Checker()
{
    mCounter = 0;
}

Gem_Checker::~Gem_Checker()
{
}
void Gem_Checker::Set_Gem(AGem* gem)
{
    if (mCounter>1)
    {
        KLOG(Warning, TEXT("%s"), TEXT("Gem_Checker->m_Counter>1"));
        return;
    }
    mSwapper[mCounter] = gem;
    mCounter = mCounter ^ 1;
}
