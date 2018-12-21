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
	GEngine->GameViewport->Viewport->LockMouseToViewport(true);

	Cursor = CreateMouseCursorWidget();
	if (Cursor)
		GetWorld()->GetFirstPlayerController()->SetMouseCursorWidget(EMouseCursor::Default, Cursor);
	else
		UE_LOG(LogTemp, Warning, TEXT("No cursor!!"));
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


UUserWidget * ATestPawn::CreateMouseCursorWidget()
{
	if (CursorWidgetClass)
	{
		return CreateWidget<UUserWidget>(GetWorld()->GetFirstPlayerController(), CursorWidgetClass);
	}

	UE_LOG(LogTemp, Warning, TEXT("No cursor set in pawn!!!"));
	return nullptr;
}

