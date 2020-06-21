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
            UINT idx = iy * sizeX + ix;

            FVector pos = { mpBoardStd->mLengthX * ix, mpBoardStd->mLengthY * iy, mpBoardStd->mBoardHight };
            AGem* spawn = Cast<AGem>(mpWorld->SpawnActor(AGem::StaticClass(), &pos));

            spawn->InitGem(PieceSeed, idx, pos, pColorObj);
            mBoard.Add(spawn);

            PieceSeed += 0.1;
        }
    }
    return true;
};//

AGem* GameBoard::GetGem(uint32 spotcountX, uint32 spotcountY)
{
    uint32 boardidx = mpBoardStd->mSizeX*spotcountY + spotcountX;  
    return mBoard[boardidx];
}

void GameBoard::SwapGem(int boardidx, int boardidx2)
{
    mBoard.Swap(boardidx,boardidx2);
}
