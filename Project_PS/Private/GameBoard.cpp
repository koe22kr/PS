// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBoard.h"
#include "PS_Std.h"
GameBoard::GameBoard()
{
}

GameBoard::~GameBoard()
{
}
bool GameBoard::MakeBoard(UINT sizeX, UINT sizeY, double seed, AGemColorObj* pColorObj)
{
    if (mpWorld == nullptr)
    {
        KLOG_S(Warning);
        return false;
    }
    mpBoardStd->mSizeX = sizeX;
    mpBoardStd->mSizeY = sizeY;
    mBoard.Reserve(sizeX*sizeY);
    double PieceSeed = seed;
    for (float iy = 0; iy < sizeY; iy++)
    {
        for (float ix = 0; ix < sizeX; ix++)
        {
            UINT8 idx = iy * ix + ix;

            FVector pos = { mpBoardStd->mLengthX * ix, mpBoardStd->mLengthY * iy, mpBoardStd->mBoardHight };
            AGem* spawn = Cast<AGem>(mpWorld->SpawnActor(AGem::StaticClass(), &pos));

            spawn->InitGem(PieceSeed, idx, pos, pColorObj);
            mBoard.Add(spawn);

            PieceSeed += 0.1;
        }
    }
    return true;
};//
