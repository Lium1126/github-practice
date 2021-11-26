# GitHub Flowの練習

## 0. 目次

1. [目標](#1-目標)
2. [対象者](#2-対象者)
3. [事前準備](#3-事前準備)
	- [Gitのインストール](#1-gitのインストール)
	- [GitHubアカウントの準備](#2-githubアカウントの準備)
	- [エディタの準備](#3-エディタの準備)
	- [makeのインストール](#4-makeのインストール)
	- [2人組の編成](#5-2人組の編成)
4. [前提知識](#4-前提知識)
	- [Gitとは？](#1-gitとは)
	- [GitHubとは？](#2-githubとは)
	- [GitHub Flowとは？](#3-github-flowとは)
5. [ハンズオン](#5-ハンズオン)
6. [最後に](#6-最後に)
7. [参考文献](#7-参考文献)

---
---

## 1. 目標
- Gitの基本的な操作をCLIから行うことができる
- [GitHub Flow](https://docs.github.com/ja/get-started/quickstart/github-flow)に則った開発が行えるようになる

## 2. 対象者
- `ls`, `cd`などのコマンドを用いてファイルを操作できる人
- C++ソースコードが多少なりとも読める人(高度な知識は必要ありません)

## 3. 事前準備
以下の5点を済ませておいてください。

- [Gitのインストール](#1-gitのインストール)
- [GitHubアカウントの準備](#2-githubアカウントの準備)
- [エディタの準備](#3-エディタの準備)
- [makeのインストール](#4-makeのインストール)
- [2人組の編成](#5-2人組の編成)

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

### 2. GitHubアカウントの準備

[GitHub](https://github.com/)からアカウントを作成してください。

また、GitHubは2021年8月からプッシュなどの操作時でのパスワード認証を廃止しています。パーソナルアクセストークンを発行していない方は、[こちら](https://docs.github.com/ja/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token)を参考に発行しておいてください。

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

## 4. 前提知識
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
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/main/repository.png" alt="リポジトリ" title="リポジトリ">
    
    リポジトリは***リモートリポジトリ***と***ローカルリポジトリ***の2種類に分けられます。
    
    ***リモートリポジトリ***とは、Gitサーバ内に保管されているリポジトリです。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/main/remote-repository.png" alt="リモートリポジトリ" title="リモートリポジトリ">
    
    ***ローカルリポジトリ***とは、ユーザごとに保有するリポジトリです。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/main/local-repository.png" alt="ローカルリポジトリ" title="ローカルリポジトリ" style="width: 50%;">
    
    ユーザは、ローカルリポジトリ内で作業を行い、その変更をリモートリポジトリに反映させることで変更点を共有します。

2. **クローン(Clone)**
    
    クローンとは、リモートリポジトリをローカルリポジトリに複製する操作です。
    
    通常、最初のみ行います。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/main/clone.png" alt="クローン" title="クローン" style="width: 50%;">
    
3. **プル(Pull)**

    プルとは、リモートリポジトリにある、持っていないファイルや他の誰かが更新したファイルをローカルリポジトリに反映させる操作です。すなわち、「自分のローカル環境を共有されているものの最新版に揃える」というような認識です。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/main/pull-1.png" alt="プル1" title="プル1" style="width: 50%;">
    
    ---
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/main/pull-2.png" alt="プル2" title="プル2" style="width: 50%;">
    
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
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/main/index.png" alt="インデックス" title="インデックス" style="width: 60%;">

7. **コミット(Commit)**

    インデックスの状態をローカルリポジトリに反映させる操作です。すなわち、施した編集をローカルリポジトリに記録する操作です。
    
    コミットを実行すると、編集した日時が記されたファイルやコミットごとのIDが生成されます。これらは時系列順に格納され、管理されます。
    
    > topic
    > 
    > もし「以前の状態に戻したい」という状況になった際には、このIDを指定することで、そのコミット時点の状態まで戻すことができます。
    
    コミットを実行する際に編集が記録されるファイルは、インデックスのファイルのみです。したがって、ステージングとはコミットするファイルを指定する操作であると言い換えることができます。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/main/commit.png" alt="コミット" title="コミット" style="width: 60%;">
        
8. **プッシュ(Push)**

    プッシュとは、ローカルリポジトリにあるファイルをリモートリポジトリに反映する操作です。
    
    ワークツリーで作業した内容をステージングによってインデックスに仮登録し、その後コミットでローカルリポジトリに反映した後、他の人へ変更を共有するためにプッシュするという流れが一般的です。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/main/push.png" alt="プッシュ" title="プッシュ" style="width: 60%;">
    
    > topic
    > 
    > ここまでで、図の左のユーザは無事変更点を共有することができました。右のユーザがその変更点を取得するためには、前述のプルをすればよいということになります。
    > 
    > <img src="https://github.com/Lium1126/github-practice-images/blob/main/pull-3.png" alt="プル3" title="プル3" style="width: 60%;">

9. **ブランチ(Branch)**

    ブランチとは、編集履歴を分岐させる機能です。これにより**あるブランチの編集が他のブランチに影響を及ぼさない**という状況を作ることができます。
    
    > topic
    > 
    > ブランチは、あるブランチのある時点から切り出して作成(分岐)するため、ブランチを作ることを俗に「ブランチを切る」と表現します。
    
    図は、`main`という名前のブランチから`fix/a`という名前のブランチを作成している例です。ブランチを切ると他ブランチに編集の影響を及ぼさないため、`main`ブランチは`fix/a`ブランチに加えた変更がなされません。
    
    これにより、`fix/a`ブランチは`main`ブランチから独立して開発を進めることができます。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/main/branch-1.png" alt="ブランチを切る" title="ブランチを切る" style="width: 50%;">

10. **マージ(Merge)**

    ブランチを分岐元となった他のブランチに併合する操作をマージと呼びます。
    
    図では、マージを行なったことにより、`main`ブランチに`fix/a`ブランチの変更が反映されました。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/main/branch-2.png" alt="マージ" title="マージ" style="width: 60%;">

### 2. GitHubとは？

GitHubは、Gitを利用するホスティングサービスの一つです。

### 3. GitHub Flowとは？

GitHub Flowとは、GitHubを用いた効率的なチーム開発のために策定されたワークフローの一つです。ワークフローってなに？という方はひとまず、業務活動をパターン化するためのルールや規約だと思ってください。

GitHub Flowでは、常に遵守されなければならない6つのルールとして、以下を定めています。

1. `main`ブランチのものは何であれデプロイ可能である
2. 新しい何かに取り組む際は、説明的な名前のブランチを`main`から作成する（例: new-oauth2-scopes）
3. 作成したブランチにローカルでコミットし、サーバー上の同じ名前のブランチにも定期的に作業内容をpushする
4. フィードバックや助言が欲しい時、ブランチをマージしてもよいと思ったときは、プルリクエストを作成する
5. 他の誰かがレビューをして機能にOKを出してくれたら、あなたはコードを`main`へマージすることができる
6. マージをして`main`へpushしたら、直ちにデプロイをする

> note
> 
> GitHub Flowの規約を調べると、デフォルトのブランチ名は`master`と表記されています。
> しかしGitHubは、IT業界の標準に合わせて2020年頃にデフォルトブランチの名前を`master`から`main`に変更しました。その後、この変更はGitHubに限らずGitLabなどのサービスでも行われ、現在主流のデフォルトブランチ名は`main`となっています。
> この流れを受け、本教材はデフォルトブランチを`main`として話を進めています。

それぞれ見ていきましょう。

1. `main`ブランチのものは何であれデプロイ可能である

    **GitHub Flowで、最も重要なルールです。**

    `main`ブランチとは、リポジトリが作られた最初の段階から存在する大元のブランチです。

    また、デプロイとは「本番環境でプログラムを動作させ、ユーザに使ってもらえる状態にする」などを含めた、ソフトウェアを利用できるようにすること全般を指す言葉です。
    
    すなわち、このルールは、**`main`ブランチは常にバグを含まないものにしろ**というような意味合いとなります。

2. 新しい何かに取り組む際は、説明的な名前のブランチを`main`から作成する（例: new-oauth2-scopes）

    ここでいう新しい何かとは、新機能追加やバグ修正などの開発作業です。
    
    このルールにより、開発者は「`main`ブランチから作成したブランチにて作業を行い、`main`ブランチにマージする」というシンプルな活動をとることになります。
    
    また、作業用ブランチを作成する際には、そのブランチがどのような作業を目的としているか分かりやすいブランチ名をつけるよう決められています。
    
    > topic
    > 
    > 作業用ブランチ名に関して、「説明的な名前をつけること」とだけ記されており、命名規則は設けられていません。

3. 作成したブランチにローカルでコミットし、サーバー上の同じ名前のブランチにも定期的に作業内容をpushする

    簡単に言えば「作業用ブランチは定期的にプッシュしなさい」というものです。

4. フィードバックや助言が欲しい時、ブランチをマージしてもよいと思ったときは、プルリクエストを作成する

    プルリクエストとは、GitHub上で「このプログラムで大丈夫そうですか？」「誰か動作確認してくれませんか？」というように、他者にアドバイスやレビューを依頼する機能です。
    
5. 他の誰かがレビューをして機能にOKを出してくれたら、あなたはコードを`main`へマージすることができる

    ここでいうレビューとは、ルール4で作成したプルリクエストに集まった評価です。
    
    このルールにより、全ての変更点(新機能やバグ修正)は第3者の確認があった後に反映(マージ)されます。
    
    > topic
    > 
    > このとき、「〇〇人OKを出したらマージしてよい」といったような規定は設けられていません。
    > 何人以上や、どういった役職の人が承認したらマージできるのかといったようなルールは組織ごとに策定してください。

6. マージをして`main`へpushしたら、直ちにデプロイをする

    全ての作業用ブランチは`main`ブランチから作成されるため(ルール2)、`main`ブランチは常に最新の状態でなければなりません。
    
<img src="https://github.com/Lium1126/github-practice-images/blob/main/github-flow.png" alt="GitHub Flow" title="GitHub Flow" style="width: 60%;">

> note
> 
> より詳しく理解したい人は、　[https://gist.github.com/Gab-km/3705015](https://gist.github.com/Gab-km/3705015)を読むことをお勧めします。

## 5. ハンズオン

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

###### フォークする前に隣のStarも押していただけると励みになります...

<img src="https://github.com/Lium1126/github-practice-images/blob/main/fork.png" alt="フォーク" title="フォーク" style="border: solid 1px gray;">

> note
> 
> フォークとは、Gitサーバ上のリポジトリを自分のリモートリポジトリに複製する操作です。よって、
> `<AさんのGitHubアカウント名>/github-practice`というリモートリポジトリが作成されます。以降は、このリポジトリに対して操作を行うことになります。

フォークを行ったら、Aさんのgithub-practiceリポジトリにBさんがアクセスできるよう設定します。

Aさんはhttps://github.com/<AさんのGitHubアカウント名>/github-practice/にアクセスしてください。

次に、下図の赤く囲んでいる「Settings」をクリックしてください。

<img src="https://github.com/Lium1126/github-practice-images/blob/main/settings.png" alt="フォーク" title="フォーク" style="border: solid 1px gray;">

移った先のページで、「Manage access」をクリックしてください。認証を求められた場合は、パスワードを用いてログインしてください。

<img src="https://github.com/Lium1126/github-practice-images/blob/main/manage-access.png" alt="フォーク" title="フォーク" style="border: solid 1px gray;">

さらに、下図で囲った「Add people」から、BさんのGitHubアカウント名で検索し、このリポジトリに対してアクセス権を持つユーザとして追加してください。

<img src="https://github.com/Lium1126/github-practice-images/blob/main/add-people.png" alt="フォーク" title="フォーク" style="border: solid 1px gray;">

上記の操作が行われると、Bさんのメールアドレスに招待メールが届きます。メールの「View invitation」をクリックしてください。これで、BさんがAさんのgithub-practiceリポジトリに対するアクセス権限を得られます。

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
	vector<int> data{29, 48, 70, 34, 92, 64, 26, 100, 15, 20, 82, 24, 79, 99, 87, 38, 14, 45, 94, 8};

	cout << endl
		 << "Before sort" << endl;
	cout << "---------------------------------------------------------------" << endl;
	printData(data);
	cout << endl;

	data = github_practice::sort(data);
	cout << "After sort" << endl;
	cout << "---------------------------------------------------------------" << endl;
	printData(data);
	cout << endl;

	cout << "Search for " << FIRST_TARGET << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << FIRST_TARGET << (github_practice::search(data, FIRST_TARGET) ? " is found!" : " is not found!") << endl;
	cout << endl;

	cout << "Search for " << SECOND_TARGET << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << SECOND_TARGET << (github_practice::search(data, SECOND_TARGET) ? " is found!" : " is not found!") << endl;

	return 0;
}
```

main.cppでは、配列dataを準備し一度内容を表示、その後ソートして同様に表示しています。その後、「38」と「75」がdataの中に含まれているか探索しています(プログラムが読めなくても、「そういった処理をしているのか」程度の理解で問題ありません)。

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

GitHub Flowでは、まず`main`ブランチから作業用ブランチを作成することから改修作業が始まります。

まずは、今どのブランチにいるのか確認しましょう。

```bash
$ git branch
* main
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
> GitHub Flow以外のワークフローには、ブランチ名を規定しているものもあります。
> 詳しくは、[Git Flow](https://qiita.com/KosukeSone/items/514dd24828b485c69a05)や[Issueドリブン開発](https://gist.github.com/Enchan1207/0ea2c7a7d6a3c16aea5683435d1972f8)について学習してください。

ブランチが作成されたことを確認します。
```bash
$ git branch
  fix-bubble-sort
* main
```

`fix-bubble-sort`ブランチが作成されたことは確認できましたが、ユーザがいるブランチは`main`ブランチのままです。ブランチの切り替えは以下のコマンドを利用します。

```bash
$ git checkout <ブランチ名>
```

作業を行うのは`fix-bubble-sort`ブランチですから、以下のコマンドを実行してブランチを切り替えてください。

```bash
$ git checkout fix-bubble-sort
Switched to branch 'fix-bubble-sort'
$ git branch
* fix-bubble-sort
  main
```

`git branch`コマンドの表示にて、`fix-bubble-sort`ブランチに<s>*</s>が付されていることが確認できたら成功です。

### 6. [Aさん]ソートアルゴリズムの変更

作業用ブランチを作成することができたため、ここからAさんにプログラムを改修してもらいます。しかし、プログラミングは本教材の本質ではないため、具体的な編集作業は**コピー&ペースト**のみとします。

<a href="https://github.com/Lium1126/github-practice/blob/main/doc/sort.md" target="_blank" rel="noopener noreferrer">ソートアルゴリズム集</a>にいくつかのソートアルゴリズムの例を示しています。

エディタを使って、**sort.cpp**の`sort`関数を、<a href="https://github.com/Lium1126/github-practice/blob/main/doc/sort.md" target="_blank" rel="noopener noreferrer">ソートアルゴリズム集</a>のバケットソートに書き換えてください(コピー&上書きペーストで構いません)。

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

すると、**sort.cpp**が`Modified（編集済み）`となっていることがわかります。「Changes not staged for commit(変更はコミットのためのステージングがなされていません)」という表記から分かるように、**sort.cpp**は`Staged`ではありません。(赤い字であることからも、`Staged`でないことを判断できます)

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

<img src="https://github.com/Lium1126/github-practice-images/blob/main/pull-request.png" alt="プルリクエスト作成" title="プルリクエスト作成" style="border: solid 1px gray;">

上記のような表記が見られない場合は、下図の「Pull Requests」タブから「New pull request」をクリックしてください。

<img src="https://github.com/Lium1126/github-practice-images/blob/main/pull-request-tab.png" alt="プルリクエスト作成" title="プルリクエスト作成" style="border: solid 1px gray;">

<strong>差分比較画面で、マージ先(「←」の左側)を、必ず「Lium1126/github-practice・main」から「<AさんのGitHubアカウント名>/github-practice・main」に変更してください。</strong>
	
その後、マージ元(「←」の右側)が「<AさんのGitHubアカウント名>/github-practice・fix-bubble-sort」となっていることを確認してください。上記2項目を確認したら、「Create pull request」をクリックします。

<img src="https://github.com/Lium1126/github-practice-images/blob/main/compare-dst.png" alt="プルリクエスト作成" title="プルリクエスト作成" style="border: solid 1px gray;">

下図のようにコメントを入力し、プルリクエストを作成します。

<img src="https://github.com/Lium1126/github-practice-images/blob/main/pull-request-comment.png" alt="プルリクエストコメント入力" title="プルリクエストコメント入力" style="border: solid 1px gray;">

### 10. [Bさん]レビュー

リモートリポジトリの`fix-bubble-sort`ブランチからプルして、動作確認を行います。

リモートリポジトリに`fix-bubble-sort`ブランチが作られたという変更をローカルブランチに反映するため、フェッチします。

```bash
$ git fetch
```

リモートリポジトリのブランチから、ローカルブランチを作成するには以下のコマンドを実行します。

```bash
$ git branch <ローカルブランチ名> <リモートブランチ名>
```

よって、以下のコマンドを実行します。

```bash
$ git branch fix-bubble-sort origin/fix-bubble-sort
```

ブランチを移動し、動作確認を行います。

```bash
$ git branch
  fix-bubble-sort
* main
$ git checkout fix-bubble-sort
$ git branch
* fix-bubble-sort
  main
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

動作確認ができたら、コードレビューをしましょう。**sort.cpp**の`sort`関数が正しく変更されているか確認してください。

確認ができたら、下図のようなコメントをつけて承認の意思を表しましょう。

<img src="https://github.com/Lium1126/github-practice-images/blob/main/LGTM.png" alt="GLTM" title="LGTM" style="border: solid 1px gray;">

> topic
> 
> LGTMとは、「Looks Good To Mee(私目線OKよ)」という意味です。プルリクエスト承認時の慣習となっている掛け声です。
> しかし、「とりあえずこれ言っておけばいいだろ」という思考停止に陥りやすいとして、この言葉を問題視する声も多くあります。

### 11. [Aさん]マージ

Bさんからの承認を得ることができたら、マージすることができます。

下図のボタンをクリックし、`main`ブランチにマージしましょう。

<img src="https://github.com/Lium1126/github-practice-images/blob/main/merge-pull-request.png" alt="プルリクエストマージ" title="プルリクエストマージ" style="border: solid 1px gray;">

### 12. [両者]プル

ここまでで、リモートリポジトリの`main`ブランチに変更を加えることができました。

最新の`main`リモートブランチを追跡するために、ローカルブランチにプルしましょう。

まず、`main`ブランチにいない場合は、`main`ブランチに切り替えます。

```bash
$ git branch
* fix-bubble-sort
  main
$ git checkout main
$ git branch
  fix-bubble-sort
* main
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

`main`ブランチに切り替えたら、リモートリポジトリの最新状態をプルしましょう。

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

### 13. [Bさん]ブランチの作成

続いて、Bさんも同様に改修作業を行います。

まずは作業用ブランチを作成しましょう。本節では、作業用ブランチを`fix-bucket-sort`とします。

```bash
$ git branch
* main
$ git branch fix-bucket-sort
$ git branch
  fix-bucket-sort
* main
$ git checkout fix-bucket-sort
Switched to branch 'fix-bucket-sort'
```

### 14. [Bさん]ソートアルゴリズムの変更

エディタを使って、**sort.cpp**の`sort`関数を、<a href="https://github.com/Lium1126/github-practice/blob/main/doc/sort.md" target="_blank" rel="noopener noreferrer">ソートアルゴリズム集</a>のシェルソートにコピー&上書きペーストしてください。

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
On branch fix-bucket-sort
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
On branch fix-bucket-sort
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	modified:   sort.cpp
```

**sort.cpp**が`Staged`になったら、コミットします。

```
$ git commit -m "<コミットメッセージ>"
[fix-bucket-sort fa826f1] <コミットメッセージ>
 1 file changed, 10 insertions(+), 6 deletions(-)
```

コミットの履歴が残されていることを確認します。

```bash
$ git log
commit <コミットID> (HEAD -> fix-bucket-sort)
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

`fix-bucket-sort`ブランチをリモートリポジトリにも作成し、そこにプッシュします。

```bash
$ git push --set-upstream origin fix-bucket-sort
```

### 17. [Bさん]プルリクエスト作成

https://github.com/<AさんのGitHubアカウント名>/github-practice/にアクセスし、プルリクエストを作成してください。

この際も、<strong>マージ先(「←」の左側)を「Lium1126/github-practice・main」から「<AさんのGitHubアカウント名>/github-practice・main」に変更することを忘れないでください。</strong>
	    
また、マージ元(「←」の右側)が「<AさんのGitHubアカウント名>/github-practice・fix-bucket-sort」となっていることを確認してください。

<img src="https://github.com/Lium1126/github-practice-images/blob/main/compare-dst.png" alt="プルリクエスト作成" title="プルリクエスト作成" style="border: solid 1px gray;">

### 18. [Aさん]レビュー

Bさんがプッシュした変更点をプルし、動作確認を行いましょう。

```bash
$ git fetch
$ git branch fix-bucket-sort origin/fix-bucket-sort
$ git branch
  fix-bucket-sort
* main
$ git checkout fix-bucket-sort
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

動作確認が完了したら、**sort.cpp**の`sort`関数が正しく変更されているか確認してください。

確認できたら、プルリクエストにレビューコメントをつけましょう。

### 19. [Bさん]マージ

Aさんから承認されたら、マージしましょう。

### 20. [両者]プル

両者プルして、ローカル`main`ブランチを最新のリモート`main`ブランチで更新します。

```bash
$ git branch
* fix-bucket-sort
  main
$ git checkout main
Switched to branch 'main'
$ git branch
  fix-bucket-sort
* main
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

チーム開発では、コンフリクト(競合)という事象が起こることがあります。コンフリクトとは、**複数人の変更箇所が重複してしまい、マージすると誰かしらの変更が失われてしまう**という状態です。

コンフリクトが起きた場合、人力で対処しなくてはなりません。以下、実際に解消する活動を行います。

### [両者]作業用ブランチ作成

Aさんは`fix-search-a`ブランチ、Bさんは`fix-search-b`ブランチを作成してください。

```bash
$ git branch fix-search-a
	    or
$ git branch fix-search-b
```

### [Aさん]編集

まずはAさんにプログラムの変更を行ってもらいます。その後、Bさんがその変更点と重複するような箇所の編集作業を行ってもらいます。

Aさんは作成した作業用ブランチに移動してください。

```bash
$ git checkout fix-search-a
```

その後、`search.cpp`の`search`関数を、<a href="https://github.com/Lium1126/github-practice/blob/main/doc/search.md" target="_blank" rel="noopener noreferrer">探索アルゴリズム集</a>の**番兵**に変更してください。

変更作業が完了したら、動作確認を行ってください。

```bash
$ make
```
正しく動作したら、状態を確認し、変更をリモートリポジトリに反映してください。

```bash
$ git status
$ git add search.cpp
$ git commit -m "<コミットメッセージ>"
$ git push --set-upstream origin fix-search-a
```

プッシュしたら、https://github.com/<AさんのGitHubアカウント名>/github-practiceにアクセスし、下図の「Compare & pull request」をクリックしてプルリクエストを作成します。図のような表示が無い場合、「Pull request」タブの「New pull request」から作成します。
	    
<img src="https://github.com/Lium1126/github-practice-images/blob/main/a-create-pullrequest.png" alt="プルリクエスト作成" title="プルリクエスト作成" style="border: solid 1px gray;">

この際も、<strong>差分比較画面で、マージ先(「←」の左側)を、必ず「Lium1126/github-practice・main」から「<AさんのGitHubアカウント名>/github-practice・main」に変更してください。</strong>
	
その後、マージ元(「←」の右側)が「<AさんのGitHubアカウント名>/github-practice・fix-search-a」となっていることを確認してください。上記2項目を確認したら、「Create pull request」をクリックします。

<img src="https://github.com/Lium1126/github-practice-images/blob/main/pullrequest-change.png" alt="マージ先変更" title="マージ先変更" style="border: solid 1px gray;">
	    
コメントを入力し、プルリクエストを作成します。
	    
<img src="https://github.com/Lium1126/github-practice-images/blob/main/pullrequest-comment.png" alt="プルリクエストコメント" title="プルリクエストコメント" style="border: solid 1px gray;">

本来なら、マージするためにはBさんがレビューを行いますが、ここでは「Bさんの知らないところでレビューが行われ、認知外でマージされてしまっていた」という想定とします。Aさんは、先ほど作成したプルリクエストをマージしてください。

### [Bさん]コンフリクトを発生させてみる

現状、前節のAさんのマージによって、`search`関数が変更されています。Bさんの作業用ブランチはその変更以前に作成されているため、`search`関数が変更されていることを追跡できていません。その状態で、Bさんも`search`関数を変更し、コンフリクトを発生させてみましょう。

まずは、ブランチを移動してください。

```bash
$ git checkout fix-search-b
```

Bさんは、`search.cpp`の`search`関数を、<a href="https://github.com/Lium1126/github-practice/blob/main/doc/search.md" target="_blank" rel="noopener noreferrer">探索アルゴリズム集</a>の**二分探索**に変更してください。

変更できたら、Bさんのローカル環境で動作確認しましょう。

```bash
$ make
```

正しく動作することが確認できたら、状態を確認し、ローカルリポジトリにコミットしましょう。

```bash
$ git status
$ git add search.cpp
$ git commit -m "<コミットメッセージ>"
```

変更をリモートリポジトリにプッシュしてください。

```bash
$ git push --set-upstream origin fix-search-b
```

ここまでで、探索アルゴリズムを**二分探索**に変更したという更新が、リモートリポジトリの`fix-search-b`ブランチに反映されました。これまで通り、プルリクエストを作成しましょう。https://<AさんのGitHubアカウント名>/github-practice/にアクセスし、下図の「Compare & pull request」をクリックします。表示が無い場合は、「Pull request」タブから「New pull request」をクリックします。

<img src="https://github.com/Lium1126/github-practice-images/blob/main/b-create-pullrequest.png" alt="プルリクエスト作成" title="プルリクエスト作成" style="border: solid 1px gray;">

これまでと同様に、<strong>差分比較画面で、マージ先(「←」の左側)を、必ず「Lium1126/github-practice・main」から「<AさんのGitHubアカウント名>/github-practice・main」に変更してください。</strong>
	
その後、マージ元(「←」の右側)が「<AさんのGitHubアカウント名>/github-practice・fix-search-b」となっていることを確認してください。上記2項目を確認したら、「Create pull request」をクリックします。

<img src="https://github.com/Lium1126/github-practice-images/blob/main/pullrequest-change2.png" alt="マージ先変更" title="マージ先変更" style="border: solid 1px gray;">

すると、下図のように「Can't automatically merge.」と表示されます。コンフリクトが発生しているマージを行おうとする際に見られる表示です。今回は、このままプルリクエストを作成します。

<img src="https://github.com/Lium1126/github-practice-images/blob/main/cant-merge.png" alt="Can't automatically merge" title="Can't automatically merge" style="border: solid 1px gray;">

プルリクエストが作成されると下図に示すように、コンフリクトが発生している旨のメッセージが確認できます。

<img src="https://github.com/Lium1126/github-practice-images/blob/main/conflict.png" alt="コンフリクト発生" title="コンフリクト発生" style="border: solid 1px gray;">

### [Bさん]コンフリクトの解消

コンフリクトを解消するにあたって、2種類の方法を示します。

1. [CLI+エディタ](#1-cliエディタ)
2. [Webページ上で解消](#2-webページ上で解消)

#### 1. CLI+エディタ



#### 2. Webページ上で解消



## 6. 最後に

今回取り上げたGitHub Flowの他にも、ワークフローはたくさんあります。また、これらのワークフローを基にした開発フローが数多く存在します。

色々な方法を身につけ、効率良いチーム開発ライフを送れることを願っております。

## 7. 参考文献
> [GitHub 入門 - IIJ Bootcamp](https://iij.github.io/bootcamp/development/github/)
> 
> [サル先生のGit入門](https://backlog.com/ja/git-tutorial/)
