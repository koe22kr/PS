// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GamePiece.h"
#include <Array.h>

/**
 * 
 */
class GameBoard
{
public:
	GameBoard();
	~GameBoard();
    bool MakeBoard(UINT sizeX, UINT sizeY) { mBoard.Init(, sizeX*sizeY); };
public:
    UINT mSizeX;
    UINT mSizeY;
    TArray<GamePiece> mBoard;
};
