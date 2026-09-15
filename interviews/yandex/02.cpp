#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

uint32_t parseIp(const string& s) {
    uint32_t result = 0;

    string part;
    stringstream ss(s);

    for (int i = 0; i < 4; ++i) {
        getline(ss, part, '.');

        result = (result << 8) | static_cast<uint32_t>(stoi(part));
    }

    return result;
}

struct Cidr {
    uint32_t network;
    int prefix;
};

Cidr parseCidr(const string& s) {
    size_t slash = s.find('/');

    string ip = s.substr(0, slash);
    int prefix = stoi(s.substr(slash + 1));

    uint32_t ipValue = parseIp(ip);

    uint32_t mask;

    if (prefix == 0) {
        mask = 0;
    } else {
        mask = 0xFFFFFFFFu << (32 - prefix);
    }

    return {
        ipValue & mask,
        prefix
    };
}

struct Server {
    uint32_t network;
    int prefix;
    int capacity;

    int used = 0;
};

struct User {
    string ipString;
    uint32_t ip;

    int start;
    int end;

    bool success = false;
};

struct TrieNode {
    int child[2] = {-1, -1};

    vector<int> servers;
};

class IpTrie {
private:
    vector<TrieNode> tree;

public:
    IpTrie() {
        tree.emplace_back();
    }

    void insert(uint32_t network, int prefix, int serverId) {
        int node = 0;

        for (int bit = 31; bit >= 32 - prefix; --bit) {
            int value = (network >> bit) & 1u;

            if (tree[node].child[value] == -1) {
                tree[node].child[value] = tree.size();
                tree.emplace_back();
            }

            node = tree[node].child[value];
        }

        tree[node].servers.push_back(serverId);
    }

    int findServer( uint32_t ip,vector<Server>& servers) {
        int node = 0;

        for (int serverId : tree[node].servers) {
            if (servers[serverId].used <
                servers[serverId].capacity) {

                return serverId;
            }
        }

        for (int bit = 31; bit >= 0; --bit) {
            int value = (ip >> bit) & 1u;

            if (tree[node].child[value] == -1) {
                break;
            }

            node = tree[node].child[value];

            for (int serverId : tree[node].servers) {
                if (servers[serverId].used <
                    servers[serverId].capacity) {

                    return serverId;
                }
            }
        }

        return -1;
    }
};

struct Event {
    int time;
    int serverId;

    bool operator>(const Event& other) const {
        return time > other.time;
    }
};

int main() {
    int p, u;

    cin >> p;
    cin >> u;

    string line;

    vector<Server> servers(p);
    IpTrie trie;

    for (int i = 0; i < p; ++i) {
        cin >> line;

        size_t comma = line.find(',');

        string cidrString = line.substr(0, comma);
        int capacity = stoi(line.substr(comma + 1));

        Cidr cidr = parseCidr(cidrString);

        servers[i].network = cidr.network;
        servers[i].prefix = cidr.prefix;
        servers[i].capacity = capacity;

        trie.insert(
            cidr.network,
            cidr.prefix,
            i
        );
    }

    vector<User> users(u);

    for (int i = 0; i < u; ++i) {
        cin >> line;

        stringstream ss(line);

        string ip;
        string start;
        string end;

        getline(ss, ip, ',');
        getline(ss, start, ',');
        getline(ss, end, ',');

        users[i].ipString = ip;
        users[i].ip = parseIp(ip);

        users[i].start = stoi(start);
        users[i].end = stoi(end);
    }

    vector<vector<int>> starts(10001);

    for (int i = 0; i < u; ++i) {
        starts[users[i].start].push_back(i);
    }

    for (auto& ids : starts) {
        sort(
            ids.begin(),
            ids.end(),
            [&](int a, int b) {
                return users[a].ip < users[b].ip;
            }
        );
    }


    priority_queue< Event, vector<Event>, greater<Event> > releases;

    set<pair<uint32_t, int>> waiting;

    for (int time = 1; time <= 10001; ++time) {

        while (!releases.empty() &&
               releases.top().time <= time) {

            int serverId = releases.top().serverId;

            --servers[serverId].used;

            releases.pop();
        }

        if (time <= 10000) {
            for (int id : starts[time]) {
                waiting.insert({
                    users[id].ip,
                    id
                });
            }
        }

        for (auto it = waiting.begin();
             it != waiting.end();) {

            int userId = it->second;
            User& user = users[userId];

            // тут тайм закончился 
            if (user.end < time) {
                it = waiting.erase(it);
                continue;
            }

            int serverId =
                trie.findServer(user.ip, servers);

            if (serverId != -1) {
   
                user.success = true;

                ++servers[serverId].used;

                releases.push({
                    user.end + 1,
                    serverId
                });

                it = waiting.erase(it);
            } else {
                ++it;
            }
        }
    }

    for (const User& user : users) {
        cout << user.ipString << ' ' << (user.success ? "SUCCESS" : "REJECT") << '\n';
    }

    return 0;
}