// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include <Array.h>

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
        mSizeX = sizeX;
        mSizeY = sizeY;
        mBoard.Reserve(sizeX*sizeY);
        double PieceSeed = seed;
        for (float iy = 0; iy < sizeY; iy++)
        {
            for (float ix = 0; ix < sizeX; ix++)
            {
                UINT8 idx = iy * ix + ix;

               FVector pos = { 80 * ix, 80 * iy, 200 };
               AGem* spawn = Cast<AGem>(mWorld->SpawnActor(AGem::StaticClass(), &pos));

               spawn->InitGem(PieceSeed, idx, pos, pColorObj);
               mBoard.Add(spawn);

                PieceSeed += 0.1;
            }
        }
        return true;
    };//
   
public:
    UWorld* mWorld;
   
    //board size
    UINT mSizeX;
    UINT mSizeY;
    TArray<AGem*> mBoard;
};
