from typing import List


class Node:
    def __init__(self, priority: int, key: int):
        self.priority = priority
        self.key = key
        self.left = None
        self.right = None

    def __str__(self):
        return f"key:{self.key},priority:{self.priority}"

    @property
    def get_children(self):
        children = []
        if self.left is not None:
            children.append(self.left)
        if self.right is not None:
            children.append(self.right)
        return children


def attach_node(root: Node, nodes: List[Node], isLeft: bool):
    """
    递归将树构件出来
    :param root:
    :param nodes:
    :param isLeft:
    """
    nodeNum = len(nodes)
    if len(nodes) == 0:
        return None
    for idx in range(int(nodeNum/2-1), -1, -1):
        children = []
        if idx*2+1 < nodeNum:
            children.append(nodes[idx*2+1])

        if idx*2+2 < nodeNum:
            children.append(nodes[idx*2+2])

        if len(children) == 0:
            continue

        minNode: Node = min(children, key=lambda x: x.priority)
        if nodes[idx].priority > minNode.priority:
            nodes[idx].priority, nodes[idx].key, minNode.priority, minNode.key = minNode.priority, minNode.key, nodes[idx].priority, nodes[idx].key
    # sortedKeys: List[int] = [node.key for node in nodes]
    nodesSortByKey: List[Node] = sorted(nodes[:], key=lambda x: x.key)
    rootIdxInNodesSortByKey = 0
    if isLeft:
        root.left = nodes[0]
    else:
        root.right = nodes[0]
    root = nodes[0]
    for idx in range(len(nodes)):
        if nodesSortByKey[idx].key == root.key:
            rootIdxInNodesSortByKey = idx
            break

    attach_node(nodes[0], nodesSortByKey[:rootIdxInNodesSortByKey], True)
    attach_node(nodes[0], nodesSortByKey[rootIdxInNodesSortByKey+1:], False)


def summit():
    nodeNum: int = int(input())
    nodes: List[Node] = []
    for idx in range(nodeNum):
        key, priority = map(int, input().split())
        nodes.append(Node(priority, key))

    root: Node = nodes[0]

    # 先进行堆排序
    for idx in range(int(nodeNum/2-1), -1, -1):
        children = []
        if idx*2+1 < nodeNum:
            children.append(nodes[idx*2+1])

        if idx*2+2 < nodeNum:
            children.append(nodes[idx*2+2])

        if len(children) == 0:
            continue

        minNode: Node = min(children, key=lambda x: x.priority)
        if nodes[idx].priority > minNode.priority:
            nodes[idx].priority, nodes[idx].key, minNode.priority, minNode.key = minNode.priority, minNode.key, nodes[idx].priority, nodes[idx].key
    # sortedKeys: List[int] = [node.key for node in nodes]
    nodesSortByKey: List[Node] = sorted(nodes[:], key=lambda x: x.key)
    rootIdxInNodesSortByKey = 0
    root = nodes[0]
    for idx in range(len(nodes)):
        if nodesSortByKey[idx].key == root.key:
            rootIdxInNodesSortByKey = idx
            break

    attach_node(nodes[0], nodesSortByKey[:rootIdxInNodesSortByKey], True)
    attach_node(nodes[0], nodesSortByKey[rootIdxInNodesSortByKey+1:], False)

    # 层次遍历
    q = [root]
    keys: List[int] = []
    priorities: List[int] = []
    while len(q) > 0:
        keys.append(q[0].key)
        priorities.append(q[0].priority)
        if q[0].left is not None:
            q.append(q[0].left)
        if q[0].right is not None:
            q.append(q[0].right)
        q.pop(0)

    print(" ".join(map(str, keys)))
    print(" ".join(map(str, priorities)))


if __name__ == '__main__':
    summit()
