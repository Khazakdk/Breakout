// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set root component
	SmBall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SmBall"));
	RootComponent = SmBall;
	SmBall->SetSimulatePhysics(true);
	SmBall->SetEnableGravity(false);
	SmBall->SetConstraintMode(EDOFMode::XZPlane);
	SmBall->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SmBall->SetCollisionProfileName(TEXT("PhysicsActor"));

	// Set movement component
    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.1;
	ProjectileMovement->Friction = 0.0;
	ProjectileMovement->Velocity.X = 0.0;

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABall::Launch()
{
	UE_LOG(LogTemp, Warning, TEXT("Launching ball"));
	SmBall->AddImpulse(FVector(140, 0, 130), FName(), true);
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

