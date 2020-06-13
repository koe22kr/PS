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
    bool MakeBoard(UINT sizeX, UINT sizeY)
    {
        for (size_t i = 0; i < sizeY; i++)
        {
            for (size_t k = 0; k < sizeX; k++)
            {
                UINT8 idx = i * k + k;

               // mBoard.Add(GamePiece(id, idx));


            }
        }
    };//
public:
    UINT mSizeX;
    UINT mSizeY;
    TArray<GamePiece> mBoard;
};
