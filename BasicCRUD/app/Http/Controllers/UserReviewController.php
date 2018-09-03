<?php

namespace App\Http\Controllers;

use App\Http\Requests\UserReviewRequest;
use App\UserReview;

class UserReviewController extends Controller
{
    /**
     * The user review instance
     *
     * @var UserReview
     */
    protected $userReview;

    /**
     * Create a new controller instance.
     *
     * @param UserReview $userReview
     */
    public function __construct(UserReview $userReview)
    {
        $this->userReview = $userReview;
    }

    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        return response()->json($this->userReview->all());
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param UserReviewRequest $request
     * @return \Illuminate\Http\Response
     */
    public function store(UserReviewRequest $request)
    {
        $this->userReview->create($request->all());
        return response()->json(["message" => "Success inserting data"]);
    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {
        return response()->json($this->userReview->find($id));
    }

    /**
     * Update the specified resource in storage.
     *
     * @param UserReviewRequest $request
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function update(UserReviewRequest $request, $id)
    {
        $this->userReview->find($id)->update($request->all());
        return response()->json(["message" => "Success editing corresponding data"]);
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        $this->userReview->destroy($id);
        return response()->json(["message" => "Success deleting corresponding data"]);
    }
}
