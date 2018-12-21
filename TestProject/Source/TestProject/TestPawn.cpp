// Fill out your copyright notice in the Description page of Project Settings.

#include "TestPawn.h"
#include "WidgetBlueprintLibrary.h"
//#include "Runtime/Engine/Classes/Components/InputComponent.h"

// Sets default values
ATestPawn::ATestPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestPawn::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;

	RestoreGameFocus();
}

// Called to bind functionality to input
void ATestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Click", IE_Released, this, &ATestPawn::RestoreGameFocus);

}

void ATestPawn::RestoreGameFocus()
{
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(GetWorld()->GetFirstPlayerController());
}

