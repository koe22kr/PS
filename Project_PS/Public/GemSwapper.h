// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Gem.h"


class Gem_Checker
{
public:
	Gem_Checker();
	~Gem_Checker();
    void Set_Gem(AGem* gem);
    
public:
    AGem* mSwapper[2];
    UINT mCounter : 1;
};
