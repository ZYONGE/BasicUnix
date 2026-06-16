# 13강 — 네트워크 관리와 시스템 관리 한 장 정리

> 유닉스기초 / TUKorea / 학교 서버: `computer.tukorea.ac.kr` (포트 `22000`)

---

## 1. 핵심 개념

| 개념 | 설명 |
|------|------|
| **클라이언트 / 서버** | 서비스를 *요청*하는 쪽(클라이언트) ↔ *제공*하는 쪽(서버). 요청→응답 관계 |
| **데몬(daemon)** | 서버에서 요청을 대기하는 백그라운드 프로세스 (예: `sshd`) |
| **포트(port)** | 서비스 구분 번호. SSH 기본 22, 웹 80/443. `/etc/services`에 정의 |
| **패킷(packet)** | 데이터를 잘게 나눈 전송 단위. 헤더(주소 정보) + 데이터로 구성 |
| **MAC 주소** | 하드웨어 고유 주소. 48비트, 16진수 6개(`:` 구분), 고정 |
| **IP 주소** | 네트워크상 식별 주소. 32비트(4바이트), 10진수 4개(`.` 구분), 가변 |
| **넷마스크** | IP에서 네트워크 부분과 호스트 부분을 구분 |
| **네트워크 인터페이스** | 컴퓨터가 네트워크에 연결되는 접점 (예: `eth0`, `lo`) |

### 주소 변환 흐름
```
이름(computer.tukorea.ac.kr) --[DNS]--> IP(210.93.48.59) --[ARP]--> MAC 주소
```
- **DNS**: 도메인 이름 → IP (인터넷 전체에 질의, 원격)
- **ARP**: IP → MAC (같은 서브넷 내부, 로컬)

---

## 2. 원격 접속: SSH

> 패킷을 **암호화**해 안전하게 전송. openssh 패키지(데몬 `sshd`), 설정 파일 `/etc/ssh/sshd_config`

### 기본 형식
| 형식 | 의미 |
|------|------|
| `ssh 호스트` | 현재 계정으로 접속 (계정 같으면 생략 가능) |
| `ssh 계정@호스트` | 다른 계정으로 접속 |
| `ssh 호스트 명령` | 접속하지 않고 원격 명령만 실행 |

### 주요 옵션
| 옵션 | 기능 |
|------|------|
| `-l 계정` | 접속 계정 지정 (`계정@호스트`와 동일) |
| `-p 포트` | 포트 지정 (**소문자 p**) |
| `-X` | X11 forwarding (GUI 창 받아오기) |

```bash
ssh -p 22000 bn23c009@computer.tukorea.ac.kr
ssh -X -p 22000 bn23c009@computer.tukorea.ac.kr   # GUI 포함
```

---

## 3. 파일 송수신: SFTP

> SSH 기반의 파일 업로드/다운로드. 전송 모드: ASCII(텍스트) / 이진(이미지·동영상·압축)

### 접속
```bash
sftp -P 22000 bn23c009@computer.tukorea.ac.kr   # 포트는 대문자 -P !
```

### 내부 명령 — 서버 쪽 vs 내 컴퓨터 쪽(l 접두사)
| 기능 | 서버 쪽 | 내 컴퓨터 쪽 |
|------|---------|--------------|
| 현재 경로 | `pwd` | `lpwd` |
| 목록 | `ls` / `dir` | `lls` |
| 디렉터리 이동 | `cd` | `lcd` |
| 디렉터리 생성 | `mkdir` | `lmkdir` |

### 전송 / 기타 (sftp 고유 명령)
| 명령 | 기능 |
|------|------|
| `get 파일` | 다운로드 (서버 → 내 컴퓨터) |
| `mget 파일들` | 여러 파일 다운로드 |
| `put 파일` | 업로드 (내 컴퓨터 → 서버) |
| `mput 파일들` | 여러 파일 업로드 |
| `!명령` | 명령을 로컬 셸에서 실행 (예: `!rm dir`) |
| `?` / `help` | 도움말 |
| `bye` / `quit` | 종료 |

> **방향 기준은 항상 "내 컴퓨터"**: get=받기, put=올리기
> **포트 옵션 주의**: ssh는 `-p`(소문자), sftp는 `-P`(대문자)

### scp (원격 복사)
```bash
scp /tmp/test 192.168.2.20:/tmp/aaa   # 로그인 없이 원격으로 파일 복사
```

---

## 4. 파일 아카이브: tar

| 작업 | 옵션 | 의미 |
|------|------|------|
| 묶기 | `c` | create |
| 풀기 | `x` | extract |
| 내용 보기 | `t` | list |
| 과정 출력 | `v` | verbose |
| 파일명 지정 | `f` | file |
| bzip2 압축 | `j` | `.tbz2` / `.tar.bz2` |
| gzip 압축 | `z` | `.tgz` / `.tar.gz` |

```bash
tar jcvf classUnix.tbz2 실습디렉터리   # 묶기 + bzip2 압축
tar jxvf classUnix.tbz2                # 풀기
tar jtvf classUnix.tbz2                # 내용 확인
```

> 확장자는 강제가 아닌 **관례**. `.tbz2` = `.tar.bz2`(tar+bzip2)이므로 항상 `j` 동반

---

## 5. 네트워크 상태 확인 명령

| 명령 | 기능 |
|------|------|
| `ifconfig [eth0]` | 인터페이스 설정 확인 (MAC, IP, 넷마스크, RX/TX) |
| `nmcli dev status` | NetworkManager 장치 상태 요약 |
| `nmcli dev show` | 장치 상세 정보 |
| `hostname` | 호스트 이름 확인/설정 (재부팅 시 초기화) |
| `uname -n` | 호스트 이름 (`-a` 전체, `-r` 커널버전, `-m` 하드웨어) |
| `nslookup 도메인` / `host` | DNS 질의 |
| `finger 사용자` | 로그인 사용자 상세 정보 |

### netstat 옵션
| 옵션 | 기능 |
|------|------|
| `-a` | 모든 연결 (대기 포함) |
| `-t` / `-u` | TCP / UDP만 |
| `-n` | 숫자(IP·포트)로 출력 |
| `-l` | LISTEN 상태만 |
| `-p` | 프로그램명/PID 표시 |
| `-r` | 라우팅 테이블 |
| `-i` | 인터페이스별 통계 |

```bash
netstat -tnlp   # 대기 중인 TCP 서비스를 프로그램명과 함께
```

### arp (IP ↔ MAC 캐시 관리)
| 옵션 | 기능 |
|------|------|
| `-a [호스트]` | 캐시 정보 출력 (지정 안 하면 전체) |
| `-d 호스트` | 항목 삭제 |
| `-f 파일` | 파일에서 읽어 캐시 추가 |
| `-v` | 자세히 출력 |

> ARP 정보는 `/proc/net/arp`에 저장. 반대 역할은 RARP(MAC→IP)

### tcpdump (패킷 캡처)
| 옵션 | 기능 |
|------|------|
| `-i eth0` | 특정 인터페이스 캡처 |
| `-c 3` | 패킷 개수 제한 |
| `-w 파일` | 파일로 저장(바이너리) |
| `-r 파일` | 저장한 파일 읽기 |
| `-X` | 내용을 16진수+ASCII로 표시 |

```bash
sudo tcpdump -c 3 tcp port 22 and host 192.168.0.17
```

---

## 6. X11 Forwarding (원격 GUI)

서버의 GUI 프로그램 창을 내 컴퓨터 화면에 띄우는 기능.

**설정 3요소**
1. 서버 `/etc/ssh/sshd_config` → `X11Forwarding yes`
2. 클라이언트 `/etc/ssh/ssh_config` → `ForwardX11 yes` (신뢰모드 `ForwardX11Trusted yes`)
3. 접속 시 `-X` 옵션 추가

```bash
ssh -X -p 22000 bn23c009@computer.tukorea.ac.kr
xclock   # 시계가 내 화면에 뜨면 성공
```

> `xhost +` 로 접근 허용, `export DISPLAY=IP:0.0` 로 출력 대상 지정

---

## 7. 세션 유지: tmux

> 터미널 멀티플렉서. 세션이 지속적이라 **접속이 끊겨도 프로그램 계속 실행**.
> 구조: **session ⊃ window ⊃ pane**. 모든 명령은 접두사 **`Ctrl+b`**로 시작

| 명령 | 기능 |
|------|------|
| `tmux` | 세션 생성 (이름 숫자 자동) |
| `tmux new -s 이름` | 이름 지정 세션 생성 |
| `tmux new -s 이름 -n 창이름` | 세션+창 함께 생성 |
| `tmux ls` | 세션 목록 |
| `Ctrl+b` → `d` | **detach** (세션 유지하고 빠져나옴) |
| `tmux attach -t 이름` (`tmux a -t`) | 세션 재접속 |
| `exit` / `Ctrl+d` | 세션 종료 (프로그램도 종료) |
| `tmux kill-session -t 이름` | 특정 세션 강제 종료 |

> **detach vs exit**: detach는 살려두고 나옴(프로그램 유지), exit은 세션 삭제(프로그램 종료)
> **주의**: `Ctrl+b`와 다음 키는 동시에 누르지 말고 떼었다가 누름

**관련 도구**: `screen`(tmux의 원형), `byobu`(screen/tmux 백엔드 + 기능키 UI)

---

## 8. 장시간 원격 작업 전체 흐름

```
ssh 접속  →  tmux new -s job  →  프로그램 실행
        →  Ctrl+b d (detach)  →  exit (SSH 종료, 프로그램은 계속)
        →  나중에 다시 ssh 접속  →  tmux ls  →  tmux a -t job  →  결과 확인
```

GUI 필요 시 `-X`(X11 forwarding), GPU 자원 필요 시 **SLURM**(`sbatch`/`salloc`/`srun`, `nvidia-smi`) 결합.

---

## 부록: 포트 옵션 대소문자 — 자주 틀리는 부분

| 명령 | 포트 옵션 |
|------|-----------|
| `ssh` | `-p` (소문자) |
| `sftp` | `-P` (대문자) |