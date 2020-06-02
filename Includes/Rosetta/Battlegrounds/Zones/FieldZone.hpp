// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef ROSETTASTONE_BATTLEGROUNDS_FIELD_ZONE_HPP
#define ROSETTASTONE_BATTLEGROUNDS_FIELD_ZONE_HPP

#include <Rosetta/Battlegrounds/Models/Minion.hpp>
#include <Rosetta/Common/Constants.hpp>

#include <array>
#include <optional>

namespace RosettaStone::Battlegrounds
{
using MinionData = std::optional<Minion>;

//!
//! \brief FieldZone class.
//!
//! This class is where the action takes place, representing the board on which
//! each game is played out. Around the battlefield are various important UI
//! elements, such as each player's hand, deck and Mana Crystals, as well as the
//! two heroes themselves. Each battlefield features its own design and numerous
//! interactive elements, but play is in no way affected or determined by
//! battlefield selection. Battlefields are chosen at random and are independent
//! of the heroes chosen by players or used by the Innkeeper.
//!
class FieldZone
{
 public:
    //! Operator overloading for operator[].
    //! \param zonePos The zone position of minion.
    //! \return The minion at \p zonePos.
    Minion& operator[](int zonePos);

    //! Adds the specified minion into this zone, at the given position.
    //! \param minion The minion to add.
    //! \param zonePos The zone position.
    void Add(Minion& minion, int zonePos = -1);

    //! Returns a value indicating whether this zone is full.
    //! \return true if this zone is full, false otherwise.
    bool IsFull() const;

 private:
    const ZoneType m_type = ZoneType::PLAY;

    std::array<MinionData, MAX_FIELD_SIZE> m_minions;
    int m_count = 0;
};
}  // namespace RosettaStone::Battlegrounds

#endif  // ROSETTASTONE_BATTLEGROUNDS_FIELD_ZONE_HPP
