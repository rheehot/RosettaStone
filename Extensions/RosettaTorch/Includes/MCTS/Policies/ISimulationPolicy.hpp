// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

// It is based on peter1591's hearthstone-ai repository.
// References: https://github.com/peter1591/hearthstone-ai

#ifndef ROSETTASTONE_TORCH_MCTS_ISIMULATION_POLICY_HPP
#define ROSETTASTONE_TORCH_MCTS_ISIMULATION_POLICY_HPP

#include <MCTS/Types.hpp>

#include <Rosetta/Games/Game.hpp>

namespace RosettaTorch::MCTS
{
//!
//! \brief ISimulationPolicy class.
//!
class ISimulationPolicy
{
 public:
    virtual ~ISimulationPolicy() = default;

    virtual bool IsEnableCutoff() = 0;

    virtual bool GetCutoffResult(const RosettaStone::Game& game, StateValue& stateValue) = 0;

    virtual void StartAction(const RosettaStone::Game& game) = 0;
};
}  // namespace RosettaTorch::MCTS

#endif  // ROSETTASTONE_TORCH_MCTS_ISIMULATION_POLICY_HPP