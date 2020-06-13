// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PS_Std.h"

/**
 * 
 */
class GamePiece
{
public:
    GamePiece(GemID id, UINT8 idx):mID(id),mIdx(idx) {};
	~GamePiece();
public:
    inline GemID& GetID() { return mID; };
    inline UINT8& GetIdx() { return mIdx; };
    inline const GemID GetID() const { return mID; };
    inline const UINT8 GetIdx() const { return mIdx; };

    inline void SetID(const GemID& setid) { mID = setid; };
    inline void SetIdx(const UINT8& setidx) { mIdx = setidx; };
    
 
private:
    GemID mID;
    UINT8 mIdx;
};
