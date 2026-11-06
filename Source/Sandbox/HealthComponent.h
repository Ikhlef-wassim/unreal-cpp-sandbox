#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(
	FOnHealthChangedSignature,
	UHealthComponent*, HealthComp,
	float, Health,
	float, HealthDelta,
	const class UDamageType*, DamageType
);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SANDBOX_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnHealthChangedSignature OnHealthChanged;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void Heal(float HealAmount);

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealth() const { return Health; }

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetMaxHealth() const { return MaxHealth; }

	UFUNCTION(BlueprintPure, Category = "Health")
	bool IsDead() const { return bIsDead; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
	float MaxHealth = 100.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	float Health = 100.0f;

	bool bIsDead = false;

	UFUNCTION()
	void HandleTakeAnyDamage(
		AActor* DamagedActor,
		float Damage,
		const class UDamageType* DamageType,
		class AController* InstigatedBy,
		AActor* DamageCauser
	);
};
