# 목표

### 결과확인 1
- floor, ceiling => RGB color
```
R 600 600

NO textures/n.xpm
SO textures/s.xpm
WE textures/w.xpm
EA textures/e.xpm
S textures/barrel.xpm

F 000, 123, 222
C 000, 222, 123

11111111111
10200200001
10000000001
10000002001
10E00100001
10100002001
10200200001
10000000021
11111111111

```
![cub3d1](https://images.velog.io/images/pawer/post/0ca28259-4f0a-43b3-b068-69a7eefb4259/cub3d1.gif)

### 결과확인 2
- floor, ceiling => Texture
- .cub파일에서 F, C값이 RGB포맷으로 주어지지 않는경우는, texture로 해석하게끔 구현했다.
- `--save` 결과

```
R 0 0
F textures/plains.xpm
C textures/cloudy.xpm
NO textures/weed_wall.xpm
EA textures/weed_wall.xpm
SO textures/weed_wall.xpm
WE textures/weed_wall.xpm
S textures/cherry_blossom.xpm

11111111111111111111111111111
10000000001100000000000000001
10110000011100000000000010001
10010000000000000000000010001
10110000011100000000000010001
10000000001100000111011110001
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000000110101000000000000001
11110111110101000000000000001
10000000001100022222000000001
10222220000000022222000000001
1022222000100002222200N000001
10222220001101022222000000001
10000000000100020000000000001
11111111111111111111111111111
```

![](https://images.velog.io/images/pawer/post/9dd32cc1-bcdc-477a-8ad9-f7df07768ea9/screenshot.bmp)

#### .cub 파일포맷을 해석하여 3d그래픽을 표현해 내야한다.

# [벡터](https://m.blog.naver.com/ruvendix/221265117926)

- 3d 그래픽을 표현하기 위해서, 벡터의 개념이 활용된다.
- 따라서, 벡터의 개념을 이해하고 진행해야 한다.

### 1. [위치 벡터, 단위 벡터 개념 이해하기](https://m.blog.naver.com/ruvendix/221191973775)
### 2. [벡터의 덧셈과 뺄셈 방법](https://m.blog.naver.com/ruvendix/221192828884)
  - 백터의 뺄셈으로 `방향` 을 구할 수 있다.  - [a벡터 - b벡터] = b벡터가 a벡터를 바라보는 방향을 구할 수 있다. (시점이 일치하는 경우에만)
  - [ 뺄셈연산의 결과 벡터의 좌표 / 뺄셈연산의 결과 벡터의 크기 ] 로 구할 수 있다.
    - 이해안되면, 링크의 내용 정독.
    
### 3. [백터의 내적](https://m.blog.naver.com/ruvendix/221207345910)
  - 백터의 내적의 결과는 `스칼라`로 표현되며, 두 백터가 이루는 각(세타)를 구할 수 있다.
  - `벡터1 크기 * 벡터2 크기 * cos세타`
  
# 레이케스팅 구현과정

- 레이캐스팅이란, 내가 서있는 위치를 기준으로 보이는 시야에 광선을 계속 쏘는것이다.
- 광선을 쏘다가 벽(또는 sprite)이랑 부딪힐 때, 거리를 계산해서 화면에 그려주면 된다.
  - .cub파일에 주어지는 [W * H] 크기의 map정보를 기준으로하여 레이케스팅을 진행한다.

#### untextured = 벽에 색깔만 입히기.
- 설명의 전체적인 흐름은 [참조](https://github.com/365kim/raycasting_tutorial)를 공부하였습니다.
- 해당링크를 따라하며 어렵게 느껴지는 부분들을 풀어서 정리한 글입니다.
- 사용되는 변수의 계산과정들은 모두 참조링크에서 확인할 수 있습니다.

### 1. 초기 값 지정.

- 맵 (worldMap)
  - 2차원배열로 표현한다.
  - `값`에 해당하는 color로 벽을 세운다. (untextured)
  - 이 때, 벽의 높이는 플레이어의 위치에따라 다르다.
- 플레이어의 위치 (posX, posY)
  - 플레이어의 시작 위치가 된다.
  - worldMap안에서 플레이어가 서있는 위치를 의미한다.
- 플레이어가 보고 있는 방향 (dirX, dirY)
  - 플레이어의 방향벡터.
- 카메라 평면의 정보
  - 카메라평면은 항상 방향벡터에서 수직이다.
  - 플레이어가 볼 수 있는 시야의 최대크기(?)를 나타낸다.
  - ~~x는 반드시 0, y의 크기에 따라 카메라 평면의 크기가 결정된다(?)~~
  - 플레이어가 보고있는 방향(동서남북)에 따라 다르다.
    - 남(S), 북(N) 쪽을 보고있을 때는 y(4분면 기준)가 값을 가진다. x = 0
    - 동(E), 서(W) 쪽을 보고있을 때는 x가 값을 가진다. y = 0
  - 초기 카메라 평면 값은 분홍색 부분의 크기를 의미한다.
  ![](https://images.velog.io/images/pawer/post/e905f84a-d3ff-4d7d-bd25-21630f1239b4/image.png)

### 2. mlxlib 사용하기.

- mlxlib는 내부적으로 [OpenGL](https://m.blog.naver.com/PostView.nhn?blogId=tlqor123&logNo=220359144262&proxyReferer=https:%2F%2Fwww.google.com%2F)와 [Appkit](https://en.wikipedia.org/wiki/Application_Kit)프레임워크를 사용하여, 3차원 공간에 그림을 그려 표현할 수 있다.
  - 3d 그래픽을 구현하기 위한 API정도(?)로 생각해도될라나 ?
  - 따라서 컴파일 옵션에 사용하는 framework를 지정해준다.
  - `gcc *.c -framework OpenGL -framework Appkit`
- 윈도우를 띄우고(mlx_new_window)
- 돌아가는 동안 해야할일을 시킨다. (mlx_loop_hook)
  - 일을 시킬때 필요한 정보가 있다면 함께 전달한다.
    - ex) 플레이어의 정보를가지고 있는 구조체
- 프로그램이 실행되면서 특정 Event가 발생했을 때 수행 될 Action이 있다면, 이 또한 알려주면 된다. (mlx_hook)
   - [mlx_hook 이해하기](https://github.com/VBrazhnik/FdF/wiki/How-to-handle-mouse-buttons-and-key-presses%3F)
   - 키가 눌리는 이벤트를 처리하려면 ?
     - X_EVENT인자에 `2`를 전달.
   - 좌측상단x(red cross)가 눌리는 이벤트를 처리하려면 ?
     - X_EVENT인자에 `17`을 전달.
   - 각 X_EVENT가 발생했을 때 처리되는 함수를 아래형식에 맞춰 전달. (int를 반환하는 함수)
     - `int (*funct)()`

#### 2-1) 돌아가는 동안 해야할일 ?
- subject의 목표는 `레이 캐스팅`을 구현하는 것이다. 우리가 해야할 일이다.
- `레이캐스팅`이란 2차원 맵에서 3차원의 원근감을 만드는 렌더링 기술이다.
  - 쉽게 2차원 배열로 선언한 맵의 `값`으로 구분하면서 원근감을 표시해 준다.
  - Detail한 부분들은 [참조링크](#레이케스팅-구현과정)를 확인.

### 3. 레이캐스팅 동작방식

- 결과적으로 플레이어의 시야를 그리는 것이다.
  - 앞으로 갈 수록 벽이 커진다.
  - 뒤로 갈 수록 벽이 작아진다.
![](https://images.velog.io/images/pawer/post/f839d361-dcca-4433-8237-f5bfbecdbf75/image.png)

#### 3-1) 위 사진처럼 일정한 간격으로 광선을 쏜다. (주황색 선.. 일정한 간격이다.. )
- 광선은 벽을 만날 때 까지 쏜다. 
(그래서 worldMap의 가장자리는 항상 벽으로 정의해야 한다.)
- 이 광선의 방향은 (rayDirX, rayDirY)로 표현한다.
- 광선의 방향을 구하기 위해 `cameraX` 변수가 사용되는데, 이는 `-1 ~ 1`의 값을 가진다.
- 결과적으로 `카메라 평면 크기`만큼 일정한 간격으로 광선을 쏘게 된다.

#### 3-2) 광선의 방향을 알았으니, 직선을 그려주면 된다.(벽을 만날때까지)
- 광선을 쏜다 == 광선 방향으로 직선을 그린다는 의미이다.
- [DDA알고리즘](https://m.blog.naver.com/PostView.nhn?blogId=kch8246&logNo=220821965260&proxyReferer=https:%2F%2Fwww.google.com%2F)을 이용한다.
- 대각의 직선을 표현하기 위해서는 지그재그 방식으로 좌표를 변경하면서 직선처럼 그려야 한다.
- 좌표는 `가로 or 세로로 한칸을 이동할 때 더 가까운 곳`으로 옮기면서 이동한다.
  - `가로로 한칸`을 움직이는 광선의 거리 == `deltaDistX` 이다.
  - `세로로 한칸`을 움직이는 광선의 거리 == `deltaDistY` 이다.
- sideDistX, sideDistY는 `최초 플레이어 위치에서 가로, 세로로 한칸을 움직인 거리` 이다. 
  - 이는 deltaDistX,Y와 플레이어의 위치로 구할 수 있다.
  - 이 변수는 이동한 만큼 늘어난다.
- 가로 or 세로 거리 중 가까운 곳을 찾았으면 이동한다.
- 즉, 가까운곳으로 광선의 위치를 늘린 후 `sideDist + deltaDist` 해준다.
- 이동한 좌표가 벽이라면, 현재위치와 벽까지의 거리를 기준으로 벽의 높이값을 구하여 그린다.

### 4. textured 레이캐스팅

- 전체적인 흐름은 untextured와 동일하다.
- 벽에 color가아닌 질감(texture)로 표현한다.
  - texture는 색깔을 조합해서 질감을 표현하는 것이다.
  - 따라서 texture를 표현하는 색의 조합을 `texture height` 만큼 저장한다.(보통 textrue는 파일로 불러와서 사용한다.)
  - 이제 해당 벽에는 color가아닌 해당하는 texture로 벽을 그리면 된다.
  - `int texture[8][texH * texW]` 와같이 정의하여 인덱스로 텍스처를 구분하여 사용. 
  - 정의한 texture에는 `텍스처 크기의 모든 픽셀은 텍스처 높이와 너비만큼 이중 반복문을 통과하면서, 텍스처 번호마다 x, y값으로 만든 특정한 값을 갖게된다.`
  - 즉, 텍스쳐구성이 `int[texH * texW]`에 저장되있다.
- 텍스쳐를 그리기위해서는 화면에 보여질 높이만큼 [스크린버퍼(buf)](https://iskim3068.tistory.com/21)에 저장한 후, 그린다.
  - 픽셀을 하나하나 그리게 된다.
- 텍스쳐를 그릴 때는 광선이 정확히 어느 지점에 부딪혔는지 알아야 한다.
  - why ??
  - 극단적으로 아래와같이 텍스쳐가 3 * 3 크기로 구성되어있다면, 광선이 파란색 부분을 캐스팅하고 있을 때, 해당 좌표에는 파란색의 벽을 세워주어야 한다. 광선의 방향을 옮겨가면서 자연스럽게 초록색 벽까지 도달하게 될 것이다.
![](https://images.velog.io/images/pawer/post/007154dc-c7c6-402c-8507-ba87f654d4fd/image.png)
- 이 정확한 위치를 나타내는 변수가 `wallX` 이다. (아래코드 참조)
  - 이름이 wallX이지만, y축과 부딪혔을 때(side = 1)는 y축을 의미한다.
  - 이 wallX를 가지고 텍스쳐 구성에서 파란색에 해당하는 인덱스 정보를 계산할 수 있다.
  - 또한 texPos을 옮길 때 step을 더해주고 있다. 
    - step 의 크기는 텍스처의 좌표를 수직선 상에 있는 좌표에 대해 얼마나 늘려야 하는지에 따라 결정 된다.
  - 이렇게 step을 사용한 텍스쳐를 표현하는 방식을[Affine 텍스쳐 매핑](https://en.wikipedia.org/wiki/Texture_mapping#Affine_texture_mapping)이라한다.

``` c
	// texturing calculations
	int texNum = worldMap[mapX][mapY]- 1;

	// calculate value of wallX
	double wallX;
	if (side == 0)
		wallX = info->posY + perpWallDist * rayDirY;
	else
		wallX = info->posX + perpWallDist * rayDirX;
	wallX -= floor((wallX));

	// x coordinate on the texture
	int texX = (int)(wallX * (double)texWidth);
    if (side == 0 && rayDirX > 0)
		texX = texWidth - texX - 1;
    if (side == 1 && rayDirY < 0)
		texX = texWidth - texX - 1;
	
        // How much to increase the texture coordinate perscreen pixel
	double step = 1.0 * texHeight / lineHeight;
	// Starting texture coordinate
	double texPos = (drawStart - height / 2 + lineHeight / 2) * step;
	for (int y = drawStart; y < drawEnd; y++)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		int texY = (int)texPos & (texHeight - 1);
		texPos += step;
		int color = info->texture[texNum][texHeight * texY + texX];
		// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		if (side == 1)
			color = (color >> 1) & 8355711;
		info->buf[y][x] = color;
	}
```
### 5. 동, 서, 남, 북에 따른 Texture 표현

- 우리가 올리는 벽의 4면 구분하여 표현한다.
  - 즉, 위쪽을 보고 있을 때는 `NO`의 texture가 오른쪽을 보고 있을 때는 `EA`의 texture가 보여야 한다. (NO, EA의 texture정보는 .cub파일에 전달 됨)
  - 이 방향을 결정하는 기준은 광선이 부딪힌 면으로 구분한다.
  - 위, 또는 아래면에 부딪힌 경우 (side == 0)에는
    - 현재 플레이어의 방향벡터(dir)의 x값(높이)이
    - 음수라면 북쪽(NO)을, 
    - 양수라면 남쪽(SO) 텍스쳐를 그린다. (2차원 배열에서 row는 index가 낮을수록 더 높은 위치를 표현한다.)
  - 광선이 좌, 우측면에 부딪힌 경우 (side == 1)에는
    - 현재 플레이어의 방향벡터(dir)의 y값(가로)이
    - 음수라면 서쪽(WE) 텍스쳐를 그린다.
    - 양수라면 동쪽(EA) 텍스쳐를 그린다. (배열표현시 col은 index가 높을수록 더 오른쪽 위치를 표현한다.)
   - 하나의 벽을 아래와 같이 세워놓게되면 플레이어가 보고있는 방향에 맞는 Texture를 그릴 수 있다.
   ![](https://images.velog.io/images/pawer/post/283e091c-79a4-4a32-be8b-d46fa12fd8f4/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-03-29%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%2012.43.46.png)
  - 즉, 위 그림의 전개도로 하나의 벽을 세워놓게되면, 플레이어가 북쪽방향을 보고있으면 N이 동쪽방향을보고있으면 E가 보이게된다.  

``` c
    void	set_ray_direction(t_ray *ray)
    {
        int	dir;

        if (ray->side)
            dir = (ray->dir.y < 0) ? (WEST) : (EAST);
        else
            dir = (ray->dir.x < 0) ? (NORTH) : (SOUTH);
        ray->eye = dir;
        return ;
    }
  ```
### 6. 좌우이동
- 기존의 `W, S` 키 입력은 현재 시선을 기준으로 앞뒤로 왔다갔다하도록 동작.
- `A D`키 입력은 현제 시선에서 좌, 우로 왔다갔다해야 함..
   - 즉, 현재위치 + 시선의 방향좌표로 증감.
- 많이헤맸는데.. lodev글에 정답이있었다.
  - plane길이로 계산하도록하면 된단다.
  - 즉, 현재 플레이어 위치에서 카메라 평면의 좌표값으로 [좌, 우]로 이동할 좌표의 step(?)값을 계산할 수 있다.
- dir로 현재 시선의 [위, 아래]좌표를 plane으로 현재 시선의 [좌, 우]를 표현.
- [참조](https://github.com/365kim/raycasting_tutorial/blob/master/4_textured_raycaster.md)

# .cub 파일?

- 레이캐스팅이 진행 될 2차원 배열의 맵 정보와, 사용될 텍스쳐의 경로, 윈도우 사이즈 등의 정보를 저장한 파일이다.
- .cub 파일을 해석하여 3D그래픽을 구현하는데 필요한 정보를 얻는다.

- F와 C의 의미는??
  - untextured 레이캐스팅을 진행할 때, 단순히 RGB 색깔 정보를 16진수로 저장하였다.
```c
		int	color;
		if (worldMap[mapY][mapX] == 1)
			color = 0xFF0000;
		else if (worldMap[mapY][mapX] == 2)
			color = 0x00FF00;
		else if (worldMap[mapY][mapX] == 3)
			color = 0x0000FF;
		else if (worldMap[mapY][mapX] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;
  
```
- 위 처럼 RGB색 정보가 .cub 파일에 `R 123,122,133` 과 같이 주어진다.
   - 이 때, 각각 RGB의 범위는 `0 ~ 255`의 값을 가진다.
   - 각 1byte공간을 차지하여 색을 표현하기 때문이다.
   - 이 내용은 다른 cardet분의 정리가 훌륭하다. 보고오면 이해가 된다. [링크](https://stdbc.tistory.com/62)
- 따라서 파일의 RGB색상을 int에 24bit공간을 사용하여 표현한다.
   - 이 때, 쉬프트 연산(`<<`)을 사용하면 된다.
   - `int color` 변수의 초기값을 0으로 만든 후
   - R = 8 ~ 15 bit, G = 16 ~ 23 bit, B = 24 ~ 31 bit에 값을 저장한다.
     - ex) F 0,1,2 일때는 R = 0, G = 2^(31 - 15), B = 2^(31 - 30) 해서 258 저장.
     - ex) F 1, 1, 1 일때는 R = 2^(31 -15), G = 2^(23 - 15), B = 2^(31 - 31) 해서 모두 더하면 65793 저장.
     - 즉 여기서 258과 65793이라는 int정수의 bit를 8비트씩 끊어서 해석하면 RGB색상을 해석할 수 있다.
 - .cub파일에서 map정보 유효성 검사
    - raycasting이 적용되기 위해서는 벽으로 둘러쌓인 map정보가 제공되어야 한다.
    - 까다로왔던 부분은 `0과 ' '`의 처리이다. 나는 아래 2가지를 가정하고 진행했다.
      - 벽 외부에는 공백(' ')으로만 표현가능하다.
      - 벽 내부에는 0으로만 표현가능하다.
    - 두가지 가정에 의하면 모든0은 벽으로 둘러쌓여있어야 한다.
      - 모든 0에 대해 [동, 서, 남, 북]방향에 벽이있는지? 확인한다.
      - 만약 (0, 0)좌표와 같은 경우에는 [동, 남]의 위치에서만 확인하도록 한다.
      - 4방위 중 한곳이라도 벽으로 둘러쌓여있지 않다면 올바르지 않은 map이라고 판단 후 error를 발생시킨다.

### --save 처리하기.

- 해당 프로그램의 첫번째 인자로 `--save`전달되면 스크린샷을 찍는다.
- `bmp` 확장자를 가진 파일을 생성한다.
  - [참조](https://dojang.io/mod/page/view.php?id=702)
  - 즉, 비트맵파일 포맷에 맞추어 화면정보를 파일로 write해준다.
    - 비트맷 파일 헤더정보를 입력해준다. 
      - 윈도우 크기정보와, 1pixel이 어떻게 표현되는지? 등등
    - 최초 화면의 데이터정보를 저장한다.
      - raycasting 쏘고
      - buf에 저장된 texture정보전체를 파일에 write해준다.
      - 그리고 프로그램 종료.

# 궁금증

### 1
#### 궁금증
- stepX, Y의 값은`-1`이 될 수 있다. 그러면 mapX, mapY가 음수가 될 수있지도 않나....? 어떻게 무조건 안되지? 
``` c
//perform DDA
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[mapX][mapY] > 0) hit = 1;
      } 
```
#### 해결
- 이거 map정보가 반드시 벽으로 둘려쌓여있다면 음수가 되기전에 반복문이 종료된다.
- 따라서 map정보만 정상적으로 파싱된다면 음수 index의 접근은 발생하지 않는다.

### 2
#### 궁금증
- 왜 광선의 백터 dir값이 x = -1, y = 0 일때 북쪽이지 ?
#### 해결
- 플레이어 기준으로 x = row, y = col을 의미한다.
- row는 -1씩 감소할 수록 높이가 커진다.
### 3
#### 궁금증
- 처음 시작위치에서 w만눌러서 벽까지 도달하면 segmentation falut에러 발생..
  - 원인을 모르겠다.. 그냥 시작위치에서 앞으로 쭉 갔을때만 그렇다 (N으로 놓고)
  - 근데 >눌러서 시야를 살짝만바꾸고 전진하면 또 안꺼진다....
  - 결국 player의 방향벡터가 1.0이라서 문제가 되는것 같다..
  - 일단은 초기 방향벡터 값을 1.0이 아닌 0.99로만 변경해줘도 조치했다..
#### 해결
  - 원인을 모르겠네 ?

# 주의사항
- 2차원 배열 arr[a][b]일 때, 좌표계로 a는 y좌표를 b는 y좌표를 의미한다.

- m1 맥북에서 컴파일할 때 gcc앞에 옵션 붙여주기
`arch -x86_64 gcc -L../mlx -lmlx -framework OpenGL -framework AppKit main.c`
