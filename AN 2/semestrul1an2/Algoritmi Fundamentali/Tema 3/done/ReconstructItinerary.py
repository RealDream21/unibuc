
class Solution(object):
    def findItinerary(self, tickets):
        tickets = list(reversed(sorted(tickets)))
        graf = {ticket[0]: [] for ticket in tickets}
        for ticket in tickets:
            graf[ticket[0]].append(ticket[1])
        
        node = "JFK"
        sol = []
        q = ["JFK"]
        while(len(q) > 0):
            if(node in graf and len(graf[node])):
                q.append(node)
                next = graf[node][-1]
                graf[node].pop()
                node = next
            else:
                sol.append(node)
                node = q[-1]
                q.pop()

        sol = list(reversed(sol))
        return sol



tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]

t = Solution()
print(t.findItinerary(tickets=tickets))