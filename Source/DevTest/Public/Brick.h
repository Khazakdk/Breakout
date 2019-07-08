// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Brick.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDestroyedSignature);

UCLASS()
class DEVTEST_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

	UPROPERTY(BlueprintAssignable)
	FDestroyedSignature DestroyedNotifier;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Static Mesh Component")
	UStaticMeshComponent* SmBrick;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision component")
	UBoxComponent* BcComponent;

	int HitsToBreak;
	float SpeedModifierOnBounce;

	UFUNCTION()
	void OnCompHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powerup Blueprint")
	TSubclassOf<class APowerup> APowerupClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};