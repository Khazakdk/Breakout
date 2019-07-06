// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Ball.h"
#include "Blueprint/UserWidget.h"
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

		UFUNCTION()
		virtual void SetupInputComponent() override;

	protected:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		bool BallLaunched;

		// Input functions
		void Launch();
		void Pause();
		void MoveHorizontal(float AxisValue);

		virtual void BeginPlay() override;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ball Blueprint")
		TSubclassOf<class ABall> ABallClass;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pause Menu Widget")
		TSubclassOf<class UUserWidget> PauseMenuWidgetClass;

		UUserWidget* PauseMenuWidget;


		ABall* Ball;
};

