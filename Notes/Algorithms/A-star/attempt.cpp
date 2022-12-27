#include <iostream> 
#include <fstream>
#include <utility> 
#include <vector>
#include <functional>
#include <cmath>

using namespace std;

class Node {
    public: 
        int g = 0;
        int h = 0;
        int f = 0;
        Node* parent;
        array <int,2> position;
        
        Node(Node* parent, array<int,2> position) {
            this -> position = position;
            this -> parent = parent;
        }

        bool equal(array <int, 2> other) {
            return position == other;
        }
};

vector<array<int,2>> astar(vector<vector<int>> maze, int start[2], int end[2]) {
    // Returns a vector of vectors as a path from the given start to the given end in the given maze

    // Create start and end node
    Node start_node(nullptr, start);
    start_node.g = start_node.h = start_node.f = 0;
    Node end_node(nullptr, end);
    end_node.g = end_node.h = end_node.f = 0;

    // Initialize both open and closed list
    vector<reference_wrapper<Node>> open_list, closed_list; 

    // Add the start node
    open_list.push_back(start_node);

    // Adjacent node relative to current node
    vector<array<int, 2>> adjacentNode;
    adjacentNode.push_back({0,-1});
    adjacentNode.push_back({0,1});
    adjacentNode.push_back({-1,0});
    adjacentNode.push_back({1,0}); 
    adjacentNode.push_back({-1,-1}); 
    adjacentNode.push_back({-1,1});
    adjacentNode.push_back({1,-1});
    adjacentNode.push_back({1,1});

    // Loop until you find the end
    while (!open_list.empty()) {
        
        // Get the current node
        reference_wrapper<Node> current_node = open_list.front().get();
        int current_index = 0;
        for (int i = 0; i < open_list.size(); i++) {
            if (open_list.at(i).get().f < current_node.get().f) {
                current_node = open_list.at(i).get();
                current_index = i;
            }
        }

        // Pop current off open list, add to closed list
        open_list.erase(open_list.begin() + current_index);
        closed_list.push_back(current_node);

        // Found the goal
        if (current_node.get().equal(end_node.position)) {
            vector<array<int, 2>> path;
            reference_wrapper<Node> current = current_node.get();
            while (true) {
                path.push_back(current.get().position);
                if (current.get().parent == nullptr) {
                    break;
                } 
                
                else {
                    current = *current.get().parent;
                }
            }
            return path; // Return unreversed path
        }

        // Generate children
        vector<reference_wrapper<Node>> children;
        for (int i = 0; i < adjacentNode.size(); i++) {

            // Get node position
            int node_position[2] = {current_node.get().position[0] + adjacentNode.at(i)[0], current_node.get().position[1] + adjacentNode.at(i)[1]};

            // Make sure within range
            if (node_position[0] > (maze.at(1).size() - 1) || node_position[0] < 0 || node_position[1] > (maze.size() - 1) || node_position[1] < 0) {
                continue;
            }

            // Make sure walkable terrain
            if (maze.at(node_position[0]).at(node_position[1]) != 0) {
                continue;
            }

            // Create new node
            Node * pointer = &current_node.get();
            Node new_node(pointer, node_position);

            // Add to children
            children.push_back(new_node);
        }

        // Loop through children
        for (reference_wrapper<Node> child : children) {

            // Child is in the closed list
            for (reference_wrapper<Node> closed_child : children) {
                if (child.get().equal(closed_child.get().position)) {
                    continue;
                }
            }

            // Create the f, g, and h values
            child.get().g = current_node.get().g + 1;
            child.get().h = sqrt(pow((child.get().position[0] - end_node.position[0]), 2) + pow((child.get().position[1] - end_node.position[1]), 2));

            for (reference_wrapper<Node> open_node : open_list) {
                if (child.get().equal(open_node.get().position) && child.get().g > open_node.get().g) {
                    continue;
                }
            }

            // Add the child to the open list
            open_list.push_back(child);
        }
    }

}


int main() {
    // vector<vector<int>> maze = {
    //         {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    //         {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    //         {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    //         {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    //         {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    //         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //         {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    //         {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    //         {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    //         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // int start[2] = {0, 0};
    // int end[2] = {7,6};

    // vector<int[2]> path = astar(maze, start, end);
    
    // for (int i = 0; i < path.size(); i++) {
    //     cout << path.at(i);
    // }
}