


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // create new nodes and insert them between the original nodes
        for (auto p = head; p; p = p->next->next) {
            auto new_node = new Node(p->val);
            new_node->next = p->next;
            p->next = new_node;
        }

        // set the random pointers for the new nodes
        for (auto p = head; p; p = p->next->next) {
            if (p->random) p->next->random = p->random->next;
        }

        // separate the new list from the original list
        auto new_head = head->next;
        for (auto p = head; p; p = p->next) {
            auto new_node = p->next;
            p->next = new_node->next;
            if (new_node->next) new_node->next = new_node->next->next;
        }

        return new_head;
    }
};