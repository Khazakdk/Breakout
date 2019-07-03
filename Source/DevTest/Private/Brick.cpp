// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Ball.h"
#include "Math/UnrealMathUtility.h"
#include "Powerup.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SmBrick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SmBrick"));
	RootComponent = SmBrick;
	SmBrick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	

	BcComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BcComponent"));
	BcComponent->SetBoxExtent(FVector(25.0, 10.0, 10.0));
	BcComponent->SetNotifyRigidBodyCollision(true);

	BcComponent->OnComponentHit.AddDynamic(this, &ABrick::OnCompHit);
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABrick::OnCompHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Hit"));
	ABall* ball = Cast<ABall>(OtherActor);
	if (ball != nullptr)
	{
		FVector ballVelocity = ball->GetVelocity();
		ballVelocity *= SpeedModifierOnBounce;
		ball->GetBall()->SetPhysicsLinearVelocity(ballVelocity, true);
		HitsToBreak--;
		if (HitsToBreak <= 0)
		{
			Super::Destroy();
			float powerupRoll = FMath::FRandRange(0.0, .99);
			if (powerupRoll > .10)
			{
				UE_LOG(LogTemp, Warning, TEXT("Attempting to spawn powerup"));
				FRotator rotation(0.0, 0.0, 0.0);
				FActorSpawnParameters spawnInfo;
				if (APowerupClass)
				{
					GetWorld()->SpawnActor<APowerup>(APowerupClass, ball->GetActorLocation(), rotation, spawnInfo);
					UE_LOG(LogTemp, Warning, TEXT("Spawned powerup"));
				}
			}
		}
	}
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

