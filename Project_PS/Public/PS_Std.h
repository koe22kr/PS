// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Project_PS.h"

/** 
 *  Puzzule & Snake objectS,Enum
 */

enum class GemColor
{
    RED,GREEN,BLUE
};

class Board_Std
{
public:
    
   UINT mSizeX;
   UINT mSizeY;
   float mLengthX;// = 80;
   float mLengthY;// = 80;
   float mBoardHight;// = 200;
   FVector2D mStartPos;
   Board_Std()
   {

       mSizeX = 10;
       mSizeY = 10;
       mLengthX = 80;
       mLengthY = 80;
       mBoardHight = 200;
       mStartPos = { 0,0 };
   };
};

//·£´ý gem id ÃßÃ· ¸¸µé±â..2