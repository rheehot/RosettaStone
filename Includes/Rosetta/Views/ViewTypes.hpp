// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef ROSETTASTONE_VIEW_TYPES_HPP
#define ROSETTASTONE_VIEW_TYPES_HPP

#include <Rosetta/Commons/Utils.hpp>
#include <Rosetta/Models/Hero.hpp>
#include <Rosetta/Models/HeroPower.hpp>
#include <Rosetta/Models/Player.hpp>
#include <Rosetta/Models/Weapon.hpp>

namespace RosettaStone::ViewTypes
{
struct Hero
{
    int attack = 0;
    int health = 0;
    int armor = 0;
    bool isStealth = false;
    bool isImmune = false;

    constexpr static int changeID = 2;

    void Fill(const RosettaStone::Hero& hero)
    {
        static_assert(changeID == 2);

        attack = hero.GetAttack();
        health = hero.GetHealth();
        armor = hero.GetArmor();
        isStealth = (hero.GetGameTag(GameTag::STEALTH) == 1);
        isImmune = (hero.GetGameTag(GameTag::IMMUNE) == 1);
    }

    bool operator==(const Hero& rhs) const
    {
        static_assert(changeID == 2);

        if (attack != rhs.attack)
        {
            return false;
        }
        if (health != rhs.health)
        {
            return false;
        }
        if (armor != rhs.armor)
        {
            return false;
        }
        if (isStealth != rhs.isStealth)
        {
            return false;
        }
        if (isImmune != rhs.isImmune)
        {
            return false;
        }

        return true;
    }

    bool operator!=(const Hero& rhs) const
    {
        return !(*this == rhs);
    }
};

struct MyHero : public Hero
{
    bool attackable = false;

    constexpr static int changeID = 1;

    void Fill(const RosettaStone::Hero& hero, bool _attackable)
    {
        Hero::Fill(hero);
        attackable = _attackable;
    }

    bool operator==(const MyHero& rhs) const
    {
        static_assert(changeID == 1);

        if (Hero::operator!=(rhs))
        {
            return false;
        }
        if (attackable != rhs.attackable)
        {
            return false;
        }

        return true;
    }

    bool operator!=(const MyHero& rhs) const
    {
        return !(*this == rhs);
    }
};

struct HeroPower
{
    std::string cardID;
    bool isExhausted = false;

    constexpr static int changeID = 1;

    void Fill(RosettaStone::HeroPower& power)
    {
        cardID = power.card.id;
        isExhausted = power.IsExhausted();
    }

    bool operator==(const HeroPower& rhs) const
    {
        static_assert(changeID == 1);

        if (cardID != rhs.cardID)
        {
            return false;
        }
        if (isExhausted != rhs.isExhausted)
        {
            return false;
        }

        return true;
    }

    bool operator!=(const HeroPower& rhs) const
    {
        return !(*this == rhs);
    }
};

struct Weapon
{
    std::string cardID;
    int attack = 0;
    int durability = 0;
    bool isEquipped = false;

    constexpr static int changeID = 1;

    void Fill(const RosettaStone::Weapon& weapon)
    {
        cardID = weapon.card.id;
        attack = weapon.GetAttack();
        durability = weapon.GetDurability();
        isEquipped = true;
    }

    void Invalidate()
    {
        isEquipped = false;
    }

    bool operator==(const Weapon& rhs) const
    {
        static_assert(changeID == 1);

        if (isEquipped != rhs.isEquipped)
        {
            return false;
        }

        if (isEquipped)
        {
            if (cardID != rhs.cardID)
            {
                return false;
            }
            if (attack != rhs.attack)
            {
                return false;
            }
            if (durability != rhs.durability)
            {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const Weapon& rhs) const
    {
        return !(*this == rhs);
    }
};

struct ManaCrystal
{
    int remaining = 0;
    int total = 0;
    int overloadOwed = 0;
    int overloadLocked = 0;

    constexpr static int changeID = 1;

    void Fill(const RosettaStone::Player& player)
    {
        remaining = player.GetRemainingMana();
        total = player.GetTotalMana();
        overloadOwed = player.GetOverloadOwed();
        overloadLocked = player.GetOverloadLocked();
    }

    bool operator==(const ManaCrystal& rhs) const
    {
        static_assert(changeID == 1);

        if (remaining != rhs.remaining)
        {
            return false;
        }
        if (total != rhs.total)
        {
            return false;
        }
        if (overloadOwed != rhs.overloadOwed)
        {
            return false;
        }
        if (overloadLocked != rhs.overloadLocked)
        {
            return false;
        }

        return true;
    }

    bool operator!=(const ManaCrystal& rhs) const
    {
        return !(*this == rhs);
    }
};

struct Minion
{
    std::string cardID;
    int attack = 0;
    int health = 0;
    bool isSilenced = false;
    bool hasTaunt = false;
    bool cantAttackHero = false;
    bool isStealth = false;
    bool isImmune = false;

    constexpr static int changeID = 3;

    void Fill(const RosettaStone::Minion& minion)
    {
        cardID = minion.card.id;
        attack = minion.GetAttack();
        health = minion.GetHealth();
        isSilenced = (minion.GetGameTag(GameTag::SILENCED) == 1);
        hasTaunt = (minion.GetGameTag(GameTag::TAUNT) == 1);
        cantAttackHero =
            (minion.GetGameTag(GameTag::CANNOT_ATTACK_HEROES) == 1);
        isStealth = (minion.GetGameTag(GameTag::STEALTH) == 1);
        isImmune = (minion.GetGameTag(GameTag::IMMUNE) == 1);
    }

    bool operator==(const Minion& rhs) const
    {
        static_assert(changeID == 3);

        if (cardID != rhs.cardID)
        {
            return false;
        }
        if (attack != rhs.attack)
        {
            return false;
        }
        if (health != rhs.health)
        {
            return false;
        }
        if (isSilenced != rhs.isSilenced)
        {
            return false;
        }
        if (hasTaunt != rhs.hasTaunt)
        {
            return false;
        }
        if (cantAttackHero != rhs.cantAttackHero)
        {
            return false;
        }
        if (isStealth != rhs.isStealth)
        {
            return false;
        }
        if (isImmune != rhs.isImmune)
        {
            return false;
        }

        return true;
    }

    bool operator!=(const Minion& rhs) const
    {
        return !(*this == rhs);
    }
};

struct MyMinion : public Minion
{
    bool attackable = false;

    constexpr static int changeID = 1;

    void Fill(const RosettaStone::Minion& minion, bool _attackable)
    {
        Minion::Fill(minion);
        attackable = _attackable;
    }

    bool operator==(const MyMinion& rhs) const
    {
        static_assert(changeID == 1);

        if (Minion::operator!=(rhs))
        {
            return false;
        }
        if (attackable != rhs.attackable)
        {
            return false;
        }

        return true;
    }

    bool operator!=(const MyMinion& rhs) const
    {
        return !(*this == rhs);
    }
};

using Minions = std::vector<Minion>;
using MyMinions = std::vector<MyMinion>;

struct MyHandCard
{
    std::string cardID;
    int cost = 0;
    int attack = 0;
    int health = 0;

    constexpr static int changeID = 1;

    void Fill(RosettaStone::Entity& entity)
    {
        cardID = entity.card.id;
        cost = entity.GetCost();
        attack = entity.GetGameTag(GameTag::ATK);
        health = entity.GetGameTag(GameTag::HEALTH);
    }

    bool operator==(const MyHandCard& rhs) const
    {
        static_assert(changeID == 1);

        if (cardID != rhs.cardID)
        {
            return false;
        }
        if (cost != rhs.cost)
        {
            return false;
        }
        if (attack != rhs.attack)
        {
            return false;
        }
        if (health != rhs.health)
        {
            return false;
        }

        return true;
    }

    bool operator!=(const MyHandCard& rhs) const
    {
        return !(*this == rhs);
    }
};

struct OpHandCard
{
    constexpr static int changeID = 1;

    bool operator==([[maybe_unused]] const OpHandCard& rhs) const
    {
        static_assert(changeID == 1);

        return true;
    }

    bool operator!=(const OpHandCard& rhs) const
    {
        return !(*this == rhs);
    }
};

using MyHand = std::vector<MyHandCard>;
using OpHand = std::vector<OpHandCard>;

struct Deck
{
    int count = 0;

    constexpr static int changeID = 1;

    void Fill(int _count)
    {
        count = _count;
    }

    bool operator==(const Deck& rhs) const
    {
        static_assert(changeID == 1);

        return count == rhs.count;
    }

    bool operator!=(const Deck& rhs) const
    {
        return !(*this == rhs);
    }
};
}  // namespace RosettaStone::ViewTypes

namespace std
{
template <>
struct hash<RosettaStone::ViewTypes::Hero>
{
    std::size_t operator()(const RosettaStone::ViewTypes::Hero& rhs) const
        noexcept
    {
        static_assert(std::decay_t<decltype(rhs)>::changeID == 2);

        std::size_t result = 0;
        CombineHash(result, rhs.attack);
        CombineHash(result, rhs.health);
        CombineHash(result, rhs.armor);
        CombineHash(result, rhs.isStealth);
        CombineHash(result, rhs.isImmune);

        return result;
    }
};

template <>
struct hash<RosettaStone::ViewTypes::MyHero>
{
    std::size_t operator()(const RosettaStone::ViewTypes::MyHero& rhs) const
        noexcept
    {
        static_assert(std::decay_t<decltype(rhs)>::changeID == 1);

        std::size_t result = std::hash<RosettaStone::ViewTypes::Hero>()(rhs);
        CombineHash(result, rhs.attackable);

        return result;
    }
};

template <>
struct hash<RosettaStone::ViewTypes::HeroPower>
{
    std::size_t operator()(const RosettaStone::ViewTypes::HeroPower& rhs) const
        noexcept
    {
        static_assert(std::decay_t<decltype(rhs)>::changeID == 1);

        std::size_t result = 0;
        CombineHash(result, rhs.cardID);
        CombineHash(result, rhs.isExhausted);

        return result;
    }
};

template <>
struct hash<RosettaStone::ViewTypes::Weapon>
{
    std::size_t operator()(const RosettaStone::ViewTypes::Weapon& rhs) const
        noexcept
    {
        static_assert(std::decay_t<decltype(rhs)>::changeID == 1);

        std::size_t result = 0;
        CombineHash(result, rhs.isEquipped);

        if (rhs.isEquipped)
        {
            CombineHash(result, rhs.cardID);
            CombineHash(result, rhs.attack);
            CombineHash(result, rhs.durability);
        }

        return result;
    }
};

template <>
struct hash<RosettaStone::ViewTypes::ManaCrystal>
{
    std::size_t operator()(
        const RosettaStone::ViewTypes::ManaCrystal& rhs) const noexcept
    {
        static_assert(std::decay_t<decltype(rhs)>::changeID == 1);

        std::size_t result = 0;
        CombineHash(result, rhs.remaining);
        CombineHash(result, rhs.total);
        CombineHash(result, rhs.overloadOwed);
        CombineHash(result, rhs.overloadLocked);

        return result;
    }
};

template <>
struct hash<RosettaStone::ViewTypes::Minion>
{
    std::size_t operator()(const RosettaStone::ViewTypes::Minion& rhs) const
        noexcept
    {
        static_assert(std::decay_t<decltype(rhs)>::changeID == 3);

        std::size_t result = 0;
        CombineHash(result, rhs.cardID);
        CombineHash(result, rhs.attack);
        CombineHash(result, rhs.health);
        CombineHash(result, rhs.isSilenced);
        CombineHash(result, rhs.hasTaunt);
        CombineHash(result, rhs.cantAttackHero);
        CombineHash(result, rhs.isStealth);
        CombineHash(result, rhs.isImmune);

        return result;
    }
};

template <>
struct hash<RosettaStone::ViewTypes::MyMinion>
{
    std::size_t operator()(const RosettaStone::ViewTypes::MyMinion& rhs) const
        noexcept
    {
        static_assert(std::decay_t<decltype(rhs)>::changeID == 1);

        std::size_t result = std::hash<RosettaStone::ViewTypes::Minion>()(rhs);
        CombineHash(result, rhs.attackable);

        return result;
    }
};

template <>
struct hash<RosettaStone::ViewTypes::Minions>
{
    std::size_t operator()(const RosettaStone::ViewTypes::Minions& rhs) const
        noexcept
    {
        std::size_t result = 0;

        for (const auto& minion : rhs)
        {
            CombineHash(result, minion);
        }

        return result;
    }
};

template <>
struct hash<RosettaStone::ViewTypes::MyMinions>
{
    std::size_t operator()(const RosettaStone::ViewTypes::MyMinions& rhs) const
        noexcept
    {
        std::size_t result = 0;

        for (const auto& minion : rhs)
        {
            CombineHash(result, minion);
        }

        return result;
    }
};

template <>
struct hash<RosettaStone::ViewTypes::MyHandCard>
{
    std::size_t operator()(const RosettaStone::ViewTypes::MyHandCard& rhs) const
        noexcept
    {
        static_assert(std::decay_t<decltype(rhs)>::changeID == 1);

        std::size_t result = 0;
        CombineHash(result, rhs.cardID);
        CombineHash(result, rhs.cost);
        CombineHash(result, rhs.attack);
        CombineHash(result, rhs.health);

        return result;
    }
};

template <>
struct hash<RosettaStone::ViewTypes::OpHandCard>
{
    std::size_t operator()([
        [maybe_unused]] const RosettaStone::ViewTypes::OpHandCard& rhs) const
        noexcept
    {
        static_assert(std::decay_t<decltype(rhs)>::changeID == 1);

        return 0;
    }
};

template <>
struct hash<RosettaStone::ViewTypes::MyHand>
{
    std::size_t operator()(const RosettaStone::ViewTypes::MyHand& rhs) const
        noexcept
    {
        std::size_t result = 0;

        for (const auto& entity : rhs)
        {
            CombineHash(result, entity);
        }

        return result;
    }
};

template <>
struct hash<RosettaStone::ViewTypes::OpHand>
{
    std::size_t operator()(const RosettaStone::ViewTypes::OpHand& rhs) const
        noexcept
    {
        std::size_t result = 0;

        for (const auto& entity : rhs)
        {
            CombineHash(result, entity);
        }

        return result;
    }
};

template <>
struct hash<RosettaStone::ViewTypes::Deck>
{
    std::size_t operator()(const RosettaStone::ViewTypes::Deck& rhs) const
        noexcept
    {
        static_assert(std::decay_t<decltype(rhs)>::changeID == 1);

        std::size_t result = 0;
        CombineHash(result, rhs.count);

        return result;
    }
};
}  // namespace std

#endif  // ROSETTASTONE_VIEW_TYPES_HPP