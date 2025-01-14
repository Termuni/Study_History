/ 조건: 0 통과 횟수가 max_zero_pass 이하인 경우에만 이동
                if (next_used <= max_zero_pass && !visited[newY][newX][next_used]) {
                    visited[newY][newX][next_used] = true;
                    q.push({newY, newX, next_used, cur.dist + 1});
                }

                // 1인 곳은 통과 횟수를 증가시키지 않음
                if (maps[newY][newX] == 1 && !visited[newY][newX][cur.used]) {
                    visited[newY][newX][cur.used] = true;
                    q.push({newY, newX, cur.used, cur.dist + 1});
                }