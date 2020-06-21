// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PS_Std.h"

#include "GameFramework/Character.h"
#include "PlayerSpot.generated.h"

class GameBoard;
class GemSwapper;
UCLASS()
class PROJECT_PS_API APlayerSpot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerSpot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* mpMesh;
    Board_Std* mpBoardStd;
    GameBoard* mpBoard;
    GemSwapper* mpSwapper;
private://|x,y count| > n  => camera move;

    void PutandSwap(int& spotCountX, int& spotCountY);
public:
    void Init();
    void Up(int& spotCountX, int& spotCountY);
    void Down(int& spotCountX, int& spotCountY);
    void Left(int& spotCountX, int& spotCountY);
    void Right(int& spotCountX, int& spotCountY);
    void Esc();// {};
};
