// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameBoard.h"


class GemSwapper
{
public:
    GemSwapper();
	~GemSwapper();
    void Put(AGem* gem);
    FVector2D Swap();
private:
    AGem* mSwapper[2];
    UINT mCounter : 1;

    bool bSwapping;
    FTimerHandle GemSwapLerpHandle;
    
};
