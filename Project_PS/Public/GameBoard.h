// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Array.h>
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Gem.h"
#include "Project_PS.h"
/**
 * 
 */
class AGemColorObj;

class GameBoard
{
public:
	GameBoard();
	~GameBoard();
    void SetUWorld(UWorld* pworld) { mWorld = pworld; };
    bool MakeBoard(UINT sizeX, UINT sizeY,double seed, AGemColorObj* pColorObj)
    {
        if (mWorld==nullptr)
        {
            KLOG_S(Warning);
            return false;
        }
        mBoard.Reserve(sizeX*sizeY);
        double PieceSeed = seed;
        for (float i = 0; i < sizeY; i++)
        {
            for (float k = 0; k < sizeX; k++)
            {
                UINT8 idx = i * k + k;

               FVector pos = { 80 * k, 80 * i, 200 };
               AGem* spawn = Cast<AGem>(mWorld->SpawnActor(AGem::StaticClass(), &pos));

               spawn->SetGem(PieceSeed, idx, pos, pColorObj);
               mBoard.Add(spawn);

                PieceSeed += 0.1;
            }
        }
        return true;
    };//
   
public:
    UWorld* mWorld;
 
    TArray<AGem*> mBoard;
};
