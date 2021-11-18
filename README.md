# GitHub Flowの練習

## 1. 目標
- Gitの基本的な操作をCLIから行うことができる
- [GitHub Flow](https://docs.github.com/ja/get-started/quickstart/github-flow)に則った開発が行えるようになる

## 3. 対象者
- `ls`, `cd`などのコマンドを用いてファイルを操作できる人
- C++ソースコードが多少なりとも読める人(高度な知識は必要ありません)

## 4. 事前準備
以下の5点を済ませておいてください。

- Gitのインストール
- GitHubアカウントの作成
- エディタの準備
- makeのインストール
- 2人組の編成

### 1. Gitのインストール
  
Gitとは、バージョン管理システムの一つです。本教材で理解を目指すGitHubとは、Gitのホスティングサービス(事業者のサーバを一部貸し出すサービス)の一つです。
OSやディストリビューションに合わせてインストールしてください。

- Windows
  
  [Downloading Git](https://git-scm.com/download/win)から「Git Bash」というアプリをダウンロード・インストールしてください。

- MacOS

  標準で使うことができます。明示的にインストールしたい場合は以下のコマンドを利用してください。
  ```bash
  $ brew install git
  ```

- Linux
  
  [Download for Linux and Unix](https://git-scm.com/download/linux)を参考にディストリビューションに合わせた方法でインストールしてください。
    
> #### note
> gitがインストールできたか確認するためには、以下のコマンドを利用してください。表示のような出力となればOKです。
> ```bash
> $ git --version
> git version 2.30.1
> ```

### 2. GitHubアカウントの作成

[GitHub](https://github.com/)からアカウントを作成してください。

### 3. エディタの準備

各自、テキストエディタを準備してください。

[VSCode](https://azure.microsoft.com/ja-jp/products/visual-studio-code/)を推奨しますが、宗教戦争案件なのでお好きなものをお使いください。

### 4. makeのインストール

以下のコマンドを実行してください。表示のような出力となればOKです。

```bash
$ make --version
GNU Make 3.81
Copyright (C) 2006  Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.

This program built for i386-apple-darwin11.3.0
```

以下に類する表示の場合、makeがインストールされていません。インストールしてください。

```bash
$ make --version
zsh: command not found: make
```

### 5. 2人組の編成
本教材は2人1組となって活動します。以下、Aさん,Bさんという表現をするため、どちらがどちらの役を行うか決めておいてください。

## 5. 前提知識
### 1. Gitとは？
前述の通り、Gitとはバージョン管理システムの一つです。

Gitの挙動を把握する上で、理解が必要になる用語がいくつか存在します。本節では、その中から以下の10個を概説します。

- リポジトリ
- クローン
- プル
- ワークツリー
- ステージング
- インデックス
- コミット
- プッシュ
- ブランチ
- マージ

1. **リポジトリ(Repository)**
  
    リポジトリとは、資産(ファイルやディレクトリ)を格納している貯蔵庫のことです。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/repository.png" alt="リポジトリ" title="リポジトリ">
    
    リポジトリは***リモートリポジトリ***と***ローカルリポジトリ***の2種類に分けられます。
    
    ***リモートリポジトリ***とは、Gitサーバ内に保管されているリポジトリです。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/remote-repository.png" alt="リモートリポジトリ" title="リモートリポジトリ">
    
    ***ローカルリポジトリ***とは、ユーザごとに保有するリポジトリです。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/local-repository.png" alt="ローカルリポジトリ" title="ローカルリポジトリ" style="width: 50%;">
    
    ユーザは、ローカルリポジトリ内で作業を行い、その変更をリモートリポジトリに反映させることで変更点を共有します。

2. **クローン(Clone)**
    
    クローンとは、リモートリポジトリをローカルリポジトリに複製する操作です。
    
    通常、最初のみ行います。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/clone.png" alt="クローン" title="クローン" style="width: 50%;">
    
3. **プル(Pull)**

    プルとは、リモートリポジトリにある、持っていないファイルや他の誰かが更新したファイルをローカルリポジトリに反映させる操作です。すなわち、「自分のローカル環境を共有されているものの最新版に揃える」というような認識です。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/pull-1.png" alt="プル1" title="プル1" style="width: 50%;">
    
    ---
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/pull-2.png" alt="プル2" title="プル2" style="width: 50%;">
    
    **先述のクローンはリモートリポジトリの内容を丸ごと複製するのに対し、プルは差分のみを更新します。**
    
    > topic
    > 
    > これに比べ、リモートリポジトリの最新情報の取得のみを行い、ファイルの更新を行わない操作をフェッチ(Fetch)と呼びます。
    > 本当にプルして良い状態か調べるときなどに使用します。

4. **ワークツリー(Working tree)**

    ワークツリーとは、作業しているディレクトリのことです。

5. **ステージング(Staged)**

    ステージングを理解する前に、Gitは変更を管理するファイルと管理しないファイルを指定できるということを知っておきましょう。
    
    Gitで変更を管理することを`track(追跡)`、しないことを`untrack`と呼びます。
    
    追跡されているファイルは以下の3つの状態のいずれかとなります。
    
    | 状態 | 内容 |
    | --- | --- |
    | Unmodified | 変更されていないファイル |
    | Modified | 変更されたファイル |
    | Staged | Commit対象のファイル |

    `Modified`のファイルを`Staged`の状態にすることをステージングと呼びます。ステージングされたファイルは、後述のインデックスに登録されます。

6. **インデックス(Index)**

    ワークツリーとは、作業しているディレクトリのことでした。それに対しインデックスは、ワークツリーとローカルリポジトリの中間に位置する場所です。ローカルリポジトリに反映させるファイルが格納されます。
    
    このインデックスが存在することにより、余分なファイルをコミットせずに済んだり、ファイルの一部だけの変更を記録してコミットすることができます。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/index.png" alt="インデックス" title="インデックス" style="width: 60%;">

7. **コミット(Commit)**

    インデックスの状態をローカルリポジトリに反映させる操作です。すなわち、施した編集をローカルリポジトリに記録する操作です。
    
    コミットを実行すると、編集した日時が記されたファイルやコミットごとのIDが生成されます。これらは時系列順に格納され、管理されます。
    
    > topic
    > 
    > もし「以前の状態に戻したい」という状況になった際には、このIDを指定することで、そのコミット時点の状態まで戻すことができます。
    
    コミットを実行する際に編集が記録されるファイルは、インデックスのファイルのみです。したがって、ステージングとはコミットするファイルを指定する操作であると言い換えることができます。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/commit.png" alt="コミット" title="コミット" style="width: 60%;">
        
8. **プッシュ(Push)**

    プッシュとは、ローカルリポジトリにあるファイルをリモートリポジトリに反映する操作です。
    
    ワークツリーで作業した内容をステージングによってインデックスに仮登録し、その後コミットでローカルリポジトリに反映した後、他の人へ変更を共有するためにプッシュするという流れが一般的です。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/push.png" alt="プッシュ" title="プッシュ" style="width: 60%;">
    
    > topic
    > 
    > ここまでで、図の左のユーザは無事変更点を共有することができました。右のユーザがその変更点を取得するためには、前述のプルをすればよいということになります。
    > 
    > <img src="https://github.com/Lium1126/github-practice-images/blob/master/pull-3.png" alt="プル3" title="プル3" style="width: 60%;">

9. **ブランチ(Branch)**

    ブランチとは、編集履歴を分岐させる機能です。これにより**あるブランチの編集が他のブランチに影響を及ぼさない**という状況を作ることができます。
    
    > topic
    > 
    > ブランチは、あるブランチのある時点から切り出して作成(分岐)するため、ブランチを作ることを俗に「ブランチを切る」と表現します。
    
    図は、`main`という名前のブランチから`fix/a`という名前のブランチを作成している例です。ブランチを切ると他ブランチに編集の影響を及ぼさないため、`main`ブランチは`fix/a`ブランチに加えた変更がなされません。
    
    これにより、`fix/a`ブランチは`main`ブランチから独立して開発を進めることができます。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/branch-1.png" alt="ブランチを切る" title="ブランチを切る" style="width: 50%;">

10. **マージ(Merge)**

    ブランチを分岐元となった他のブランチに併合する操作をマージと呼びます。
    
    図では、マージを行なったことにより、`main`ブランチに`fix/a`ブランチの変更が反映されました。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/branch-2.png" alt="マージ" title="マージ" style="width: 60%;">

### 2. GitHubとは？

GitHubは、Gitを利用するホスティングサービスの一つです。

### 3. GitHub Flowとは？

GitHub Flowとは、GitHubを用いた効率的なチーム開発のために策定されたルール(規約)の一つです。

GitHub Flowでは、常に遵守されなければならない6つのルールとして、以下を定めています。

1. `master`ブランチのものは何であれデプロイ可能である
2. 新しい何かに取り組む際は、説明的な名前のブランチを`master`から作成する（例: new-oauth2-scopes）
3. 作成したブランチにローカルでコミットし、サーバー上の同じ名前のブランチにも定期的に作業内容をpushする
4. フィードバックや助言が欲しい時、ブランチをマージしてもよいと思ったときは、プルリクエストを作成する
5. 他の誰かがレビューをして機能にOKを出してくれたら、あなたはコードを`master`へマージすることができる
6. マージをして`master`へpushしたら、直ちにデプロイをする

それぞれ見ていきましょう。

1. `master`ブランチのものは何であれデプロイ可能である

    **GitHub Flowで、最も重要なルールです。**

    `master`ブランチとは、リポジトリが作られた最初の段階から存在する大元のブランチです。

    また、デプロイとは「本番環境でプログラムを動作させ、ユーザに使ってもらえる状態にする」などを含めた、ソフトウェアを利用できるようにすること全般を指す言葉です。
    
    すなわち、このルールは、**`master`ブランチは常にバグを含まないものにしろ**というような意味合いとなります。

2. 新しい何かに取り組む際は、説明的な名前のブランチを`master`から作成する（例: new-oauth2-scopes）

    ここでいう新しい何かとは、新機能追加やバグ修正などの開発作業です。
    
    このルールにより、開発者は「`master`ブランチから作成したブランチにて作業を行い、`master`ブランチにマージする」というシンプルな活動をとることになります。
    
    また、作業用ブランチを作成する際には、そのブランチがどのような作業を目的としているか分かりやすいブランチ名をつけるよう決められています。
    
    > topic
    > 
    > 作業用ブランチ名に関して、「説明的な名前をつけること」とだけ記されているのみで命名規則は設けられていません。

3. 作成したブランチにローカルでコミットし、サーバー上の同じ名前のブランチにも定期的に作業内容をpushする

    簡単に言えば「作業用ブランチは定期的にプッシュしなさい」というものです。

4. フィードバックや助言が欲しい時、ブランチをマージしてもよいと思ったときは、プルリクエストを作成する

    プルリクエストとは、GitHub上で「このプログラムで大丈夫そうですか〜？」「誰か動作確認してくれませんか〜？」というように、他者にアドバイスやレビューを依頼する機能です。
    
5. 他の誰かがレビューをして機能にOKを出してくれたら、あなたはコードを`master`へマージすることができる

    ここでいうレビューとは、ルール4で作成したプルリクエストに集まった評価です。
    
    このルールにより、全ての変更点(新機能やバグ修正)は第3者の確認があった後に反映(マージ)されます。
    
    > topic
    > 
    > このとき、「〇〇人OKを出したらマージしてよい」といったような規定は設けられていません。
    > 何人以上や、どういった役職の人が承認したらマージできるのかといったようなルールは組織ごとに策定してください。

6. マージをして`master`へpushしたら、直ちにデプロイをする

    全ての作業用ブランチは`master`ブランチから作成されるため(ルール2)、`master`ブランチは常に最新の状態でなければなりません。
    
<img src="https://github.com/Lium1126/github-practice-images/blob/master/github-flow.png" alt="GitHub Flow" title="GitHub Flow" style="width: 60%;">

> note
> 
> より詳しく理解したい人は、　[https://gist.github.com/Gab-km/3705015](https://gist.github.com/Gab-km/3705015)を読むことをお勧めします。

## 6. ハンズオン

> note
> 
> 以降、`<>`で囲まれた情報は適宜置き換えてください。例えば
> ```bash
> $ git config --global user.name '<あなたのユーザ名>'
> ```
> は、筆者の場合
> ```bash
> $ git config --global user.name 'Lium1126'
> ```
> となります。

### 1. [Aさん]リポジトリのフォーク

Aさんはこのリポジトリをフォークしてください。

下図の「Fork」をクリックします。

<img src="https://github.com/Lium1126/github-practice-images/blob/master/fork.png" alt="フォーク" title="フォーク" style="border: solid 1px gray;">

> note
> 
> フォークとは、Gitサーバ上のリポジトリを自分のリモートリポジトリに複製する操作です。よって、
> `<AさんのGitHubアカウント名>/github-practice`というリモートリポジトリが作成されます。以降は、このリポジトリに対して操作を行うことになります。

### 2. [両者]Git設定の確認

以下のコマンドを実行して、出力に下記の表示が含まれているか確認してください。

```bash
$ git config -l
user.email=<あなたのメールアドレス>
user.name=<あなたのGitHubアカウント名>
```

上記の表示が得られない場合、お使いの環境にGitアカウントの設定がされていません。

その場合、以下のコマンドで設定してください。

```bash
$ git config --global user.name '<自分の名前>'
$ git config --global user.email '<自分のメールアドレス>'
```

例えば、筆者の場合は以下のようにします。

```bash
$ git config --global user.name 'Lium1126'
$ git config --global user.email 'yosi.4sya@gmail.com'
```

> topic
> 
> `--global`オプションを指定することで、あらゆるリポジトリでこの設定が反映されるようにします。

### 3. [両者]リポジトリのクローン

任意のディレクトリに、フォークしたリポジトリをクローンします。

以下のコマンドを実行してください。

```bash
$ mkdir github_flow_handson
$ cd github_flow_handson
$ git clone https://github.com/<AさんのGitHubアカウント名>/github-practice.git
Cloning into 'github-practice'...
remote: Enumerating objects: 50, done.
remote: Counting objects: 100% (50/50), done.
remote: Compressing objects: 100% (47/47), done.
remote: Total 50 (delta 21), reused 17 (delta 2), pack-reused 0
Receiving objects: 100% (50/50), 17.81 KiB | 1.48 MiB/s, done.
Resolving deltas: 100% (21/21), done.
$ ls
github-practice
$ cd github-practice
```

クローンが完了すると、リモートリポジトリにあるファイルが複製され、ローカルリポジトリが作成されます。

> note
> 
> 空のローカルリポジトリを作成したい場合は、
> ```bash
> $ git init
> ```
> コマンドを利用します。これを使用した場合、プッシュ時にリモートリポジトリを作成します。

ファイルが正しく複製されたか確認してください。

```bash
$ ls
Makefile   README.md  doc        main.cpp   search.cpp search.hpp sort.cpp   sort.hpp
```

### 4. [両者]内容の確認

クローンしたリポジトリには、既にプログラムを作成してあります。

少し中身を見てみましょう。

**main.cpp**内の`main`関数は以下のようになっています。

```c++
#define FIRST_TARGET 38
#define SECOND_TARGET 75

int main(const int argc, const char *argv[])
{
	srand(time(NULL));
	vector<int> data{29, 48, 70, 34, 92, 64, 26, 100, 15, 20, 82, 24, 79, 99, 87, 38, 14, 45, 94, 8};

	cout << endl
		 << "Before sort" << endl;
	cout << "---------------------------------------------------------------" << endl;
	printData(data);
	cout << endl;

	data = githubPractice::sort(data);
	cout << "After sort" << endl;
	cout << "---------------------------------------------------------------" << endl;
	printData(data);
	cout << endl;

	cout << "Search for " << FIRST_TARGET << endl;
	cout << "---------------------------------------------------------------" << endl;
	if (githubPractice::search(data, FIRST_TARGET))
		cout << FIRST_TARGET << " is found!" << endl;
	else
		cout << FIRST_TARGET << " is not found!" << endl;
	cout << endl;

	cout << "Search for " << SECOND_TARGET << endl;
	cout << "---------------------------------------------------------------" << endl;
	if (githubPractice::search(data, SECOND_TARGET))
		cout << SECOND_TARGET << " is found!" << endl;
	else
		cout << SECOND_TARGET << " is not found!" << endl;
	cout << endl;

	return 0;
}
```

main.cppでは、配列dataを準備し一度内容を表示、その後ソートして同様に表示しています。その後、「38」と「75」がdataの中に含まれているか探索しています。

ソートしている`sort`関数は**sort.cpp**に記述されており、***バブルソート***が実装されています。

```c++
std::vector<int> sort(std::vector<int> data)
{
  for (int i = 0; i < data.size() - 1; i++)
  {
    for (int j = data.size() - 1; j > i; j--)
    {
      if (data[j] < data[j - 1])
      {
        int tmp = data[j];
        data[j] = data[j - 1];
        data[j - 1] = tmp;
      }
    }
  }
  return data;
}
```

また、指定した値を探索する`search`関数は**search.cpp**に実装されており、***線形探索***で実装されています。

```c++
bool search(std::vector<int> data, int target)
{
  for (int x : data)
  {
    if (x == target)
      return true;
  }

  return false;
}
```

プログラムを実行してみましょう。

以下のコマンドを実行し、表示のような出力が得られれば正しくプログラムが動作しています。

```bash
$ make
Before sort
---------------------------------------------------------------
29 48 70 34 92 64 26 100 15 20 82 24 79 99 87 38 14 45 94 8

After sort
---------------------------------------------------------------
8 14 15 20 24 26 29 34 38 45 48 64 70 79 82 87 92 94 99 100

Search for 38
---------------------------------------------------------------
38 is found!

Search for 75
---------------------------------------------------------------
75 is not found!
```

### 5. [Aさん]ブランチの作成

ここから、Aさんがこのプログラムに対して改修作業を行うという想定でハンズオンを行います。

GitHub Flowでは、まず`master`ブランチから作業用ブランチを作成することから改修作業が始まります。

まずは、今どのブランチにいるのか確認しましょう。

```bash
$ git branch
* master
```

`git branch`は、ローカルリポジトリ内のブランチ一覧と、今いるブランチを表示します。<s>*</s>の付いているブランチが現在いるブランチです。

ブランチを作成するには、以下のコマンドを使用します。このコマンドを実行すると、今いるブランチから分岐した新しいブランチが作成されます。

```bash
$ git branch <新しいブランチ名>
```

ここでは、以下のようなブランチ名で新たなブランチを作成しましょう。

```bash
$ git branch fix-bubble-sort
```

> topic
> 
> GitHub Flow以外の開発フローには、ブランチ名を規定しているものもあります。
> 詳しくは、[Git Flow](https://qiita.com/KosukeSone/items/514dd24828b485c69a05)や[Issueドリブン開発](https://gist.github.com/Enchan1207/0ea2c7a7d6a3c16aea5683435d1972f8)について学習してください。

ブランチが作成されたことを確認します。
```bash
$ git branch
  fix-bubble-sort
* master
```

`fix-bubble-sort`ブランチが作成されたことは確認できましたが、ユーザがいるブランチは`master`ブランチのままです。ブランチの切り替えは以下のコマンドを利用します。

```bash
$ git checkout <ブランチ名>
```

作業を行うのは`fix-bubble-sort`ブランチですから、以下のコマンドを実行してブランチを切り替えてください。

```bash
$ git checkout fix-bubble-sort
Switched to branch 'fix-bubble-sort'
$ git branch
* fix-bubble-sort
  master
```

`git branch`コマンドの表示にて、`fix-bubble-sort`ブランチに<s>*</s>が付されていることが確認できたら成功です。

### 6. [Aさん]ソートアルゴリズムの変更

作業用ブランチを作成することができたため、ここからAさんにプログラムを改修してもらいます。しかし、プログラミングは本教材の本質ではないため、具体的な編集作業は**コピー&ペースト**のみとします。

<a href="https://github.com/Lium1126/github-practice/blob/master/doc/sort.md" target="_blank" rel="noopener noreferrer">ソートアルゴリズム集</a>にいくつかのソートアルゴリズムの例を示しています。

エディタを使って、**sort.cpp**の`sort`関数を、<a href="https://github.com/Lium1126/github-practice/blob/master/doc/sort.md" target="_blank" rel="noopener noreferrer">ソートアルゴリズム集</a>のバケットソートに書き換えてください(コピー&上書きペーストで構いません)。

プログラムの変更ができたら、正しく動作することを確認してください。

```bash
$ make
Before sort
---------------------------------------------------------------
29 48 70 34 92 64 26 100 15 20 82 24 79 99 87 38 14 45 94 8

After sort
---------------------------------------------------------------
8 14 15 20 24 26 29 34 38 45 48 64 70 79 82 87 92 94 99 100

Search for 38
---------------------------------------------------------------
38 is found!

Search for 75
---------------------------------------------------------------
75 is not found!
```

> topic
> 
> このように、関数の外部仕様と内部仕様を分離することで、変更の影響が他に及ばないようにすることがチーム開発では重要です。今回の例では、main.cppに影響を及ぼさず、sort.cppを改修することができました。

### 7. [Aさん]コミット

変更を加えたファイルの状態を確認してみましょう。

```bash
$ git status
On branch fix-bubble-sort
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
	modified:   sort.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```

すると、**sort.cpp**が`Modified（編集済み）`となっていることがわかります。赤字は`Staged`でないことを表しています。

変更をコミットするためには、ステージングをしてインデックスに登録しなければなりませんでした。そこで、以下のコマンドで**sort.cpp**をステージングします。

```bash
$ git add sort.cpp
```

ここでは何も表示されませんが、再度確認すると**sort.cpp**が`Staged`になっていることが確認できます。

```bash
$ git status
On branch fix-bubble-sort
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	modified:   sort.cpp
```

> topic
> 
> `git add`コマンドは、`git add -A`とすると「`Untrack`や`Unmodified`の全てのファイルを一括でステージングする」ということができます。
> しかし、不要なファイルまでステージングしてしまうといったリスクがあるため、乱用に注意してください。

ここまでで、**sort.cpp**がインデックスに登録され、コミットの準備が整いました。コミットしてみましょう。

```bash
$ git commit
```

上記コマンドを実行すると、エディタが起動してコミットメッセージの入力が求められます。

```bash
<任意のコミットメッセージ>

# Please enter the commit message for your changes. Lines starting
# with '#' will be ignored, and an empty message aborts the commit.
#
# Date:   Thu Nov 18 17:30:35 2021 +0900
#
# On branch fix-bubble-sort
#
# Initial commit
#
# Changes to be committed:
#   new file:   sort.cpp
#
```

コミットメッセージを入力し、ファイルを保存すればコミット完了です。

> note
> 
> コミットメッセージとは、そのコミットがどのような変更を加えたのか、なぜその変更を加えたのかを表すコメントです。
> 変更履歴を辿ったり、以前のバージョンに戻したりするときの目印として活用します。

> topic
> 
> `git commit`コマンドは、`-m`オプションを利用することでエディタを起動せずにコミットすることができます。書式は以下の通りです。
> ```bash
> $ git commit -m "<任意のコミットメッセージ>"
> ```

コミットの履歴が残されていることを確認します。

```bash
$ git log
commit <コミットID> (HEAD -> fix-bubble-sort)
Author: <AさんのGitHubアカウント名> <<Aさんのメールアドレス>>
Date:   Thu Nov 18 17:30:35 2021 +0900

    <コミットメッセージ>
```

`git show`コマンドを実行すると、直前の変更の差分を確認することができます。`+`の部分が追加された箇所、`-`の部分が削除された箇所です。

```bash
$ git show
```

### 8. [Aさん]プッシュ

ローカルリポジトリにコミットできたので、リモートリポジトリに変更を反映しましょう。

プッシュと同時に現在のブランチをリモートリポジトリにも作成します。

```bash
$ git push --set-upstream origin <ブランチ名>
```

変更を加えたブランチは`fix-bubble-sort`であったので、以下のコマンドを実行することになります。

```bash
$ git push --set-upstream origin fix-bubble-sort
```

> note
> 
> すでにリモートリポジトリにブランチが作成されている場合は
> ```bash
> $ git push
> ```
> を利用することができます。

### 9. [Aさん]プルリクエスト作成

https://github.com/<AさんのGitHubアカウント名>/github-practice/にアクセスし、下図に示すような「Compare & pull request」をクリックします。

<img src="https://github.com/Lium1126/github-practice-images/blob/master/pull-request.png" alt="プルリクエスト作成" title="プルリクエスト作成" style="border: solid 1px gray;">

下図のようにコメントを入力し、プルリクエストを作成します。

<img src="https://github.com/Lium1126/github-practice-images/blob/master/pull-request-comment.png" alt="プルリクエストコメント入力" title="プルリクエストコメント入力" style="border: solid 1px gray;">

### 10. [Bさん]レビュー

リモートリポジトリの`fix-bubble-sort`ブランチからプルして、動作確認を行います。

リモートリポジトリのブランチから、ローカルブランチを作成するには以下のコマンドを実行します。

```bash
$ git branch <ローカルブランチ名> <リモートブランチ名>
```

よって、以下のコマンドを実行します。

```bash
git branch fix-bubble-sort origin/fix-bubble-sort
```

ブランチを移動し、動作確認を行います。

```bash
$ git branch
  fix-bubble-sort
* master
$ git checkout fix-bubble-sort
$ git branch
* fix-bubble-sort
  master
$ make
Before sort
---------------------------------------------------------------
29 48 70 34 92 64 26 100 15 20 82 24 79 99 87 38 14 45 94 8

After sort
---------------------------------------------------------------
8 14 15 20 24 26 29 34 38 45 48 64 70 79 82 87 92 94 99 100

Search for 38
---------------------------------------------------------------
38 is found!

Search for 75
---------------------------------------------------------------
75 is not found!
```

プログラムの動作確認ができたら、下図のようなコメントをつけて承認の意思を表しましょう。

<img src="https://github.com/Lium1126/github-practice-images/blob/master/LGTM.png" alt="GLTM" title="LGTM" style="border: solid 1px gray;">

> topic
> 
> LGTMとは、「Looks Good To Mee(私目線OKよ)」という意味です。プルリクエスト承認時の慣習となっている掛け声です。
> しかし、「とりあえずこれ言っておけばいいだろ」という思考停止に陥りやすいとして、この言葉を問題視する声も多くあります。

### 11. [Aさん]マージ

Bさんからの承認を得ることができたら、マージすることができます。

下図のボタンをクリックし、`master`ブランチにマージしましょう。

<img src="https://github.com/Lium1126/github-practice-images/blob/master/merge-pull-request.png" alt="プルリクエストマージ" title="プルリクエストマージ" style="border: solid 1px gray;">

### 12. [両者]プル

ここまでで、リモートリポジトリの`master`ブランチに変更を加えることができました。

最新の`master`リモートブランチを追跡するために、ローカルブランチにプルしましょう。

まず、`master`ブランチにいない場合は、`master`ブランチに切り替えます。

```bash
$ git branch
* fix-bubble-sort
  master
$ git checkout master
$ git branch
  fix-bubble-sort
* master
```

> note
> 
> 不要になったローカルブランチを削除しても構いません。ブランチを削除するコマンドは以下の通りです。
> ```bash
> $ git branch -d <ブランチ名>
> ```
> 
> よって、`fix-bubble-sort`ブランチを削除する場合は
> ```bash
> $ git branch -d fix-bubble-sort
> ```
> を実行します。

`master`ブランチに切り替えたら、リモートリポジトリの最新状態をプルしましょう。

```bash
$ git pull
```

**sort.cpp**の`sort`関数が、バブルソートから以下のように変更されていれば、Aさんの編集が正しく共有されています。

```c++
std::vector<int> sort(std::vector<int> data)
{

	// calculate bucket size
	int bucket_size = data[0];
	for (int i = 1; i < data.size(); i++)
	{
		if (data[i] > bucket_size)
		{
			bucket_size = data[i];
		}
	}
	bucket_size += 1;

	// create empty buckets
	std::vector<int> bucket[bucket_size];

	// put data elements into buckets depending on the value
	for (int i = 0; i < data.size(); i++)
	{
		bucket[data[i]].push_back(data[i]);
	}

	// concatenate all buckets into data
	int id = 0;
	for (int i = 0; i < bucket_size; i++)
	{
		for (int j = 0; j < bucket[i].size(); j++)
		{
			data[id++] = bucket[i][j];
		}
	}

	return data;
}
```

> topic
> 
> フェッチを行う場合は以下のコマンドを利用します。
> ```bash
> $ git fetch
> ```

### 13. [Bさん]ブランチの作成

続いて、Bさんも同様に改修作業を行います。

まずは作業用ブランチを作成しましょう。本節では、作業用ブランチを`fix-backet-sort`とします。

```bash
$ git branch
* master
$ git branch fix-backet-sort
$ git branch
  fix-backet-sort
* master
$ git checkout fix-backet-sort
Switched to branch 'fix-backet-sort'
```

### 14. [Bさん]ソートアルゴリズムの変更

エディタを使って、**sort.cpp**の`sort`関数を、<a href="https://github.com/Lium1126/github-practice/blob/master/doc/sort.md" target="_blank" rel="noopener noreferrer">ソートアルゴリズム集</a>のシェルソートに上書きペーストしてください。

ソートアルゴリズムを変更したら、動作確認してください。

```bash
$ make
Before sort
---------------------------------------------------------------
29 48 70 34 92 64 26 100 15 20 82 24 79 99 87 38 14 45 94 8

After sort
---------------------------------------------------------------
8 14 15 20 24 26 29 34 38 45 48 64 70 79 82 87 92 94 99 100

Search for 38
---------------------------------------------------------------
38 is found!

Search for 75
---------------------------------------------------------------
75 is not found!
```

### 15. [Bさん]コミット

バケットソートからシェルソートへの変更をローカルリポジトリに登録するため、ステージングします。

まずは**sort.cpp**の状態を確認します。

```bash
$ git status
On branch fix-backet-sort
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
	modified:   sort.cpp
	
no changes added to commit (use "git add" and/or "git commit -a")
```

**sort.cpp**が`Modified`であることが確認できたら、ステージングを行います。

```bash
$ git add sort.cpp
$ git status
On branch fix-backet-sort
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	modified:   sort.cpp
```

**sort.cpp**が`Staged`になったら、コミットします。

```
$ git commit -m "<コミットメッセージ>"
[fix-backet-sort fa826f1] <コミットメッセージ>
 1 file changed, 10 insertions(+), 6 deletions(-)
```

コミットの履歴が残されていることを確認します。

```bash
$ git log
commit <コミットID> (HEAD -> fix-backet-sort)
Author: <BさんのGitHubアカウント名> <<Bさんのメールアドレス>>
Date:   Thu Nov 18 17:30:35 2021 +0900

    <コミットメッセージ>
```

直近のコミットの変更点を確認します。

```bash
$ git show
```

`sort`関数が書き換えられていることが確認できましたか？

### 16. [Bさん]プッシュ

正しく編集・コミットできたら、リモートリポジトリに対してプッシュしましょう。

`fix-backet-sort`ブランチをリモートリポジトリにも作成し、そこにプッシュします。

```bash
$ git push --set-upstream origin fix-backet-sort
```

### 17. [Bさん]プルリクエスト作成

https://github.com/<AさんのGitHubアカウント名>/github-practice/にアクセスし、プルリクエストを作成してください。

### 18. [Aさん]レビュー

Bさんがプッシュした変更点をプルし、動作確認を行いましょう。

```bash
$ git branch fix-backet-sort origin/fix-backet-sort
$ git branch
  fix-backet-sort
* master
$ git checkout fix-backet-sort
$ make
Before sort
---------------------------------------------------------------
29 48 70 34 92 64 26 100 15 20 82 24 79 99 87 38 14 45 94 8

After sort
---------------------------------------------------------------
8 14 15 20 24 26 29 34 38 45 48 64 70 79 82 87 92 94 99 100

Search for 38
---------------------------------------------------------------
38 is found!

Search for 75
---------------------------------------------------------------
75 is not found!
```

正しく動作することが確認できたら、プルリクエストにレビューコメントをつけましょう。

### 19. [Bさん]マージ

Aさんから承認されたら、マージしましょう。

### 20. [両者]プル

両者プルして、ローカル`master`ブランチを最新のリモート`master`ブランチで更新します。

```bash
$ git branch
* fix-backet-sort
  master
$ git checkout master
Switched to branch 'master'
$ git branch
  fix-backet-sort
* master
$ git pull
```

**sort.cpp**の`sort`関数が以下のように変更されているか確認してください。

```c++
std::vector<int> sort(std::vector<int> data)
{
	for (int h = data.size() / 2; h > 0; h /= 2)
	{
		for (int i = h; i < data.size(); i += 1)
		{
			int k = data[i];

			int j;
			for (j = i; j >= h && data[j - h] > k; j -= h)
			{
				data[j] = data[j - h];
			}

			data[j] = k;
		}
	}

	return data;
}
```

### 21. コンフリクト

チーム開発では、コンフリクト(競合)という事象が起こることがあります。

コンフリクトとは、**複数人の変更箇所が重複してしまい、マージすると誰かしらの変更が失われてしまう**という状態です。

コンフリクトが起きた場合、人力で対処しなくてはなりません。

## 7. 最後に

今回取り上げたGitHub Flowの他にも、ワークフローはたくさんあります。また、これらのワークフローを基にした開発フローが数多く存在します。

色々な方法を身につけ、効率良いチーム開発ライフを送れることを願っております。

## 8. 参考文献
> [GitHub 入門 - IIJ Bootcamp](https://iij.github.io/bootcamp/development/github/)
> [サル先生のGit入門](https://backlog.com/ja/git-tutorial/)
