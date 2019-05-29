// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BreakoutPC.generated.h"

/**
 * 
 */
UCLASS()
class DEVTEST_API ABreakoutPC : public APlayerController
{
	GENERATED_BODY()

	public:
		// Sets default values for this actor's properties
		ABreakoutPC();

		virtual void SetupInputComponent() override;

	protected:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		float speed;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		bool bBallLaunched;

		// Input functions
		void Launch();
		void Pause();
		void MoveHorizontal(float AxisValue);
};

