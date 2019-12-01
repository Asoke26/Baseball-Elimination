# Baseball-Elimination

Problem Description :
---------------------
<p align="justify">
Baseball Elimination is a classic problem of MaxFlow Mincut algorithm. Given the standings in a sports league at some point during the season, determine which teams have been mathematically eliminated from winning their division.

In the baseball elimination problem, there is a league consisting of N teams. At some point during the season, team i has w_i wins and r_ij games left to play against team j. A team is eliminated if it cannot possibly finish the season in first place or tied for first place. The goal is to determine exactly which teams are eliminated.</p>

<p align="center">
  <img width=auto height=auto src="https://github.com/Asoke26/Baseball-Elimination/blob/master/data/figures/1.PNG">
</p>
 <br />
Figure 1: Sample Point table



Montreal is mathematically eliminated since it can finish with at most 80 wins and Atlanta already has 83 wins.Philadelphiais also mathematically eliminated. It can finish the season with as many as 83 wins, which appears to be enough to tieAtlanta. But this would require Atlanta to lose all of its remaining games, including the 6 against New York, in which case New York would finish with 84 wins. We note thatNew Yorkis not yet mathematically eliminated despite the fact that it has fewer wins than Philadelphia.

Input:
------
Input consists of Multiple lines. First line have variable N that denotes number of teams. Following N lines will have team name labeled/indexed as {0,1...N-1}, number of wins,number of loses, remaining games to be played and distribution of remaining games against each teams. Figure 1 describes a sample input for required program.

Output:
-------
Output will be team name {0,1...N-1}, separated by space. e.g. 0 2 if 0 and 2 are the teams eliminated. <br />
Output for Figure 1 :<br />
1 2<br />

# Assumptions
Assume that no games end in a tie,no rainouts, Ignore wildcard possibilities,assume that there are no whitespace characters in the name of a team.

# References: 
[1] https://www.cs.princeton.edu/courses/archive/spr03/cs226/assignments/baseball.html <br />
[2] https://www.cs.princeton.edu/~wayne/papers/baseball_talk.pdf <br />
[3] https://github.com/nastra/AlgorithmsPartII-Princeton


