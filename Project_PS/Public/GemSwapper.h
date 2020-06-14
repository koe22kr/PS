// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Gem.h"


class GemSwapper
{
public:
    GemSwapper();
	~GemSwapper();
    void Set_Gem(AGem* gem);
    
public:
    AGem* mSwapper[2];
    UINT mCounter : 1;
};
