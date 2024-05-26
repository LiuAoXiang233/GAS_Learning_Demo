// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/MyAuraManaEffectActor.h"

#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAttributeSet.h"

void AMyAuraManaEffectActor::OnOverlap(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor,
                                       UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: 我们现在直接改变的这个指针中的const元素可以访问，但是之后应该实现。
	if(IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));

		UAuraAttributeSet* MutableAuraAttributeSet = const_cast<UAuraAttributeSet*>(AuraAttributeSet);
		MutableAuraAttributeSet->SetMana(AuraAttributeSet->GetMana() + 40.f);
		Destroy();
	}
}


