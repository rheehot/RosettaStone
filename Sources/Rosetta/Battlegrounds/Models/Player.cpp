// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Rosetta/Battlegrounds/Cards/Cards.hpp>
#include <Rosetta/Battlegrounds/Models/Player.hpp>

namespace RosettaStone::Battlegrounds
{
void Player::SelectHero(std::size_t idx)
{
    const auto heroCard = Cards::FindCardByDbfID(heroChoices.at(idx));
    hero.Initialize(heroCard);

    selectHeroCallback();
}

void Player::PrepareTavern()
{
    prepareTavernMinionsCallback(*this);
}

void Player::PurchaseMinion(std::size_t idx)
{
    if (remainCoin < NUM_COIN_PURCHASE_MINION)
    {
        return;
    }

    handZone.Add(tavernMinions.Remove(tavernMinions[idx]), -1);
    remainCoin -= NUM_COIN_PURCHASE_MINION;
}

void Player::PlayCard(std::size_t handIdx, std::size_t fieldIdx)
{
    auto card = handZone.Remove(handZone[handIdx]);

    if (std::holds_alternative<Minion>(card))
    {
        auto minion = std::get<Minion>(card);
        minions.Add(minion, fieldIdx);
    }
    else
    {
        // TODO: Cast spell
    }
}

void Player::SellMinion(std::size_t idx)
{
    const auto minion = minions.Remove(minions[idx]);
    returnMinionCallback(minion.GetPoolIndex());

    remainCoin += 1;
}

void Player::UpgradeTavern()
{
    if (currentTier == TIER_UPPER_LIMIT || remainCoin < coinToUpgradeTavern)
    {
        return;
    }

    remainCoin -= coinToUpgradeTavern;
    upgradeTavernCallback(*this);
}

void Player::RefreshTavern()
{
    if (remainCoin < NUM_COIN_REFRESH_TAVERN)
    {
        return;
    }

    clearTavernMinionsCallback(tavernMinions);
    remainCoin -= NUM_COIN_REFRESH_TAVERN;

    prepareTavernMinionsCallback(*this);
}

void Player::RearrangeMinion(std::size_t curIdx, std::size_t newIdx)
{
    if (curIdx == newIdx || static_cast<int>(curIdx) >= minions.GetCount() ||
        static_cast<int>(newIdx) >= minions.GetCount())
    {
        return;
    }

    minions.Move(static_cast<int>(curIdx), static_cast<int>(newIdx));
}
}  // namespace RosettaStone::Battlegrounds
