// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
//#include "Engine/World.h"

#include "Gem.h"
/**
 * 
 */
class AGemColorObj;

class GameBoard
{
public:
	GameBoard();
	~GameBoard();
    void Init(UWorld* pworld, Board_Std* pboardstd) 
    {
        mpWorld = pworld; 
        mpBoardStd = pboardstd;
    };
    bool MakeBoard(uint32 sizeX, uint32 sizeY, double seed, AGemColorObj* pColorObj);
    AGem* GetGem(uint32 idxX, uint32 idxY);
    void SwapGem(int boardidx, int boardidx2);
    //AGem* GetGem(AGem* gem)
public:
    UWorld* mpWorld;
    Board_Std* mpBoardStd;
    //board size
    
    TArray<AGem*> mBoard;
};
