// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Powerup.generated.h"

UCLASS()
class DEVTEST_API APowerup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Static Mesh Component")
	UStaticMeshComponent* SmSphere;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
