class MyHashSet {
    ListNode* head;

public:
    MyHashSet() { head = new ListNode(-1); }

    void add(int key) {
        ListNode* tmp = head;
        while (tmp->next != NULL && tmp->next->val <= key) {
            if (tmp->next->val == key)
                return;
            tmp = tmp->next;
        }
        ListNode* next = tmp->next;
        ListNode* newNode = new ListNode(key, next);
        tmp->next = newNode;
    }

    void remove(int key) {
        ListNode* tmp = head;
        while (tmp->next != NULL && tmp->next->val <= key) {
            if (tmp->next->val == key) {
                tmp->next = tmp->next->next;
                break;
            }
            tmp = tmp->next;
        }
    }

    bool contains(int key) {
        ListNode* tmp = head->next;
        while (tmp != NULL && tmp->val <= key) {
            if (tmp->val == key)
                return true;
            tmp = tmp->next;
        }
        return false;
    }
};