# 1. 작업할 폴더 생성 및 이동
mkdir DX11_Study
cd DX11_Study

# 2. Git 저장소 초기화
git init

# 3. 원격 저장소 연결
git remote add origin https://github.com/piusAI/DirectX11_withRastertek.git

# 4. 특정 폴더만 가져오도록 설정
git config core.sparseCheckout true

# 5. 다운로드할 폴더 경로 등록
echo rasterteck04_D3D/ >> .git/info/sparse-checkout

# 6. 소스 가져오기 (이때 로그인 창이 뜨면 로그인하세요)
git pull origin main
