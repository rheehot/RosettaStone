// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <hspp/Tasks/TaskSerializer.h>
#include <hspp/Tasks/Tasks.h>

namespace Hearthstonepp
{
MetaData ITask::Run(Player& player)
{
    return Impl(player);
}

MetaData ITask::Run(Player& player, TaskMeta& meta)
{
    const MetaData status = Impl(player);
    meta = Serializer::CreateGameStatus(player, GetTaskID(), status);

    return status;
}
}  // namespace Hearthstonepp
