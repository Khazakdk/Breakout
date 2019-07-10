// Fill out your copyright notice in the Description page of Project Settings.


#include "Powerup.h"

// Sets default values
APowerup::APowerup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SmSphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SmSphere"));
	RootComponent = SmSphere;
	SmSphere->SetSimulatePhysics(true);
	SmSphere->SetEnableGravity(true);
	SmSphere->SetConstraintMode(EDOFMode::XZPlane);
	SmSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SmSphere->SetCollisionProfileName(TEXT("OverlapAll"));
	SmSphere->SetMassOverrideInKg(TEXT("SmSphere"), 0.5, true);
	SmSphere->SetLinearDamping(4.0);
}

// Called when the game starts or when spawned
void APowerup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

